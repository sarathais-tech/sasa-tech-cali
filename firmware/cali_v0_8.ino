#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <math.h>

// SASA TECH - CALI V0.8 - boca animada e comentarios espontaneos
// Firmware do prototipo simulado no Wokwi
Adafruit_SSD1306 tela(128, 64, &Wire, -1);
Adafruit_MPU6050 mpu;
const int BOTAO = 18, TRIG = 5, ECHO = 19;
enum Humor { FELIZ, CURIOSO, TONTO, IRRITADO, CARINHO, ACALMADO, DESCONFORTAVEL };
float estresse = 0, movimento = 0, distancia = 400;
unsigned long ultimoCiclo = 0, ultimaTela = 0, ultimoSensor = 0, ultimoLog = 0;
unsigned long tontoAte = 0, carinhoAte = 0, acalmadoAte = 0;
bool leituraAnterior = HIGH, botaoEstavel = HIGH, estavaPerto = false;
unsigned long mudouEm = 0, ultimaAproximacao = 0;
int aproximacoes = 0;


/*
 * Fala visual: a boca e a legenda aparecem por 2,5 segundos.
 * Fora desse intervalo, Cali observa em silencio (so olhos).
 * Comentarios "espontaneos" sao frases predefinidas por temporizador.
 */
Humor ultimoHumor = FELIZ;
unsigned long falaAte = 0;
unsigned long proximoComentario = 0;
unsigned long ultimaFala = 0;
uint8_t variacaoFala = 0;
bool falando = false;
const char* falaAtual = "";

const char* fraseDoHumor(Humor humor, uint8_t indice) {
  switch (humor) {
    case FELIZ: return indice ? "Planos secretos..." : "Ola, mamae Sasa!";
    case CURIOSO: return indice ? "Um novo humano?" : "Quem esta ai?";
    case TONTO: return indice ? "Vou reclamar!" : "MAMAE! Tontura!";
    case IRRITADO: return indice ? "Exijo respeito!" : "Nao me sacode!";
    case CARINHO: return indice ? "Obrigado, mamae!" : "Recebi carinho!";
    case ACALMADO: return indice ? "Melhor assim..." : "Ufa... paz!";
    case DESCONFORTAVEL: return indice ? "Muita intimidade!" : "Espaco pessoal!";
  }
  return "";
}

void iniciarFala(const char* frase, unsigned long agora) {
  falaAtual = frase;
  falando = true;
  falaAte = agora + 2500;
  ultimaFala = agora;
  Serial.print("Cali diz: ");
  Serial.println(frase);
}

void atualizarFala(Humor humor, unsigned long agora) {
  if (falando && (long)(agora - falaAte) >= 0) falando = false;

  if (humor != ultimoHumor) {
    ultimoHumor = humor;
    variacaoFala = 0;
    iniciarFala(fraseDoHumor(humor, variacaoFala), agora);
    proximoComentario = agora + 12000;
    return;
  }

  // Sem repetir falas automaticamente em toda emocao.
  // Apenas no repouso surgem observacoes ocasionais.
  if (humor == FELIZ && (long)(agora - proximoComentario) >= 0) {
    variacaoFala = (variacaoFala + 1) % 2;
    iniciarFala(fraseDoHumor(FELIZ, variacaoFala), agora);
    proximoComentario = agora + random(12000, 22000);
  }
}

void desenharBoca(Humor humor, unsigned long agora) {
  // y=44 a 49: separado da legenda que comeca em y=55
  bool aberta = (agora / 250) % 2 == 0;
  if (!aberta) {
    tela.drawFastHLine(59, 46, 12, WHITE);
    return;
  }
  switch (humor) {
    case FELIZ:
    case CARINHO:
    case ACALMADO:
      tela.drawLine(57, 44, 64, 49, WHITE);
      tela.drawLine(64, 49, 71, 44, WHITE);
      break;
    case IRRITADO:
    case DESCONFORTAVEL:
      tela.drawLine(57, 48, 71, 44, WHITE);
      break;
    case TONTO:
      tela.drawCircle(64, 46, 4, WHITE);
      break;
    case CURIOSO:
      tela.fillCircle(64, 46, 3, WHITE);
      break;
  }
}

float lerDistancia() {
  digitalWrite(TRIG, LOW); delayMicroseconds(2);
  digitalWrite(TRIG, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  unsigned long duracao = pulseIn(ECHO, HIGH, 25000);
  if (duracao == 0) return 400;
  return duracao * 0.0343 / 2.0;
}
void desenhar(Humor humor, bool piscando) {
  tela.clearDisplay();
  tela.setTextColor(SSD1306_WHITE);
  tela.setTextSize(1);
  switch (humor) {
    case FELIZ:
      if (piscando) {
        tela.drawFastHLine(30, 28, 24, WHITE);
        tela.drawFastHLine(74, 28, 24, WHITE);
      } else {
        tela.fillRoundRect(30, 15, 24, 29, 9, WHITE);
        tela.fillRoundRect(74, 15, 24, 29, 9, WHITE);
      }
      break;
    case CURIOSO:
      tela.fillCircle(42, 29, 15, WHITE);
      tela.fillCircle(86, 29, 15, WHITE);
      tela.fillCircle(42, 29, 6, BLACK);
      tela.fillCircle(86, 29, 6, BLACK);
      break;
    case TONTO:
      tela.setTextSize(3);
      tela.setCursor(19, 17); tela.print("@");
      tela.setCursor(72, 17); tela.print("@");
      break;
    case IRRITADO:
      tela.drawLine(26, 19, 54, 31, WHITE);
      tela.drawLine(74, 31, 102, 19, WHITE);
      tela.drawFastHLine(30, 34, 24, WHITE);
      tela.drawFastHLine(74, 34, 24, WHITE);
      tela.drawFastHLine(53, 49, 22, WHITE);
      break;
    case DESCONFORTAVEL:
      tela.fillCircle(42, 27, 9, WHITE);
      tela.fillCircle(86, 27, 9, WHITE);
      break;
    case CARINHO:
      tela.fillRoundRect(30, 15, 24, 29, 9, WHITE);
      tela.fillRoundRect(74, 15, 24, 29, 9, WHITE);
      break;
    case ACALMADO:
      tela.drawLine(30, 28, 42, 33, WHITE);
      tela.drawLine(42, 33, 54, 28, WHITE);
      tela.drawLine(74, 28, 86, 33, WHITE);
      tela.drawLine(86, 33, 98, 28, WHITE);
      break;
  }
  if (falando) {
    desenharBoca(humor, millis());
    tela.setTextSize(1);
    tela.setCursor(2, 55);
    tela.print(falaAtual);
  }
  tela.display();
}
void setup() {
  Serial.begin(115200);
  pinMode(BOTAO, INPUT_PULLUP);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Wire.begin(21, 22);
  if (!tela.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Erro OLED"); while (true) delay(100);
  }
  if (!mpu.begin()) {
    Serial.println("Erro MPU6050"); while (true) delay(100);
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  tela.clearDisplay();
  tela.setTextSize(1);
  tela.setTextColor(WHITE);
  tela.setCursor(28, 24); tela.print("SASA TECH");
  tela.setCursor(35, 40); tela.print("CALI V0.8");
  tela.display();
  delay(1500);
  ultimoCiclo = millis();
  randomSeed(micros());
  proximoComentario = ultimoCiclo + 3500;
}
void loop() {
  unsigned long agora = millis();
  float dt = (agora - ultimoCiclo) / 1000.0f;
  ultimoCiclo = agora;
  bool leitura = digitalRead(BOTAO);
  if (leitura != leituraAnterior) mudouEm = agora;
  if (agora - mudouEm > 40 && leitura != botaoEstavel) {
    botaoEstavel = leitura;
    if (botaoEstavel == LOW) {
      estresse = max(0.0f, estresse - 30.0f);
      carinhoAte = agora + 2000;
      acalmadoAte = agora + 5000;
      Serial.println("Carinho recebido!");
    }
  }
  leituraAnterior = leitura;
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  float intensidade = sqrt(g.gyro.x*g.gyro.x +
                           g.gyro.y*g.gyro.y +
                           g.gyro.z*g.gyro.z);
  movimento = 0.7f * movimento + 0.3f * intensidade;
  if (movimento > 1.5f) tontoAte = agora + 1800;
  if (movimento > 1.0f) estresse += 15.0f * dt;
  else estresse -= 5.0f * dt;
  if (agora - ultimoSensor >= 200) {
    distancia = lerDistancia();
    ultimoSensor = agora;
    bool perto = distancia < 100;
    if (perto && !estavaPerto) {
      if (agora - ultimaAproximacao > 10000) aproximacoes = 0;
      aproximacoes++;
      ultimaAproximacao = agora;
      Serial.println("Objeto se aproximou!");
      if (aproximacoes >= 3) {
        estresse += 20;
        aproximacoes = 0;
        Serial.println("Cali ficou incomodado!");
      }
    }
    estavaPerto = perto;
  }
  estresse = constrain(estresse, 0.0f, 100.0f);
  Humor humor = FELIZ;
  if (agora < carinhoAte) humor = CARINHO;
  else if (agora < acalmadoAte) humor = ACALMADO;
  else if (agora < tontoAte) humor = TONTO;
  else if (estresse >= 60) humor = IRRITADO;
  else if (distancia < 30) humor = DESCONFORTAVEL;
  else if (distancia < 100) humor = CURIOSO;
  atualizarFala(humor, agora);
  if (agora - ultimaTela >= 100) {
    bool piscando = (agora % 3000 < 180);
    desenhar(humor, piscando);
    ultimaTela = agora;
  }
  if (agora - ultimoLog >= 500) {
    Serial.print("Distancia: ");
    Serial.print(distancia, 1);
    Serial.print(" cm | Estresse: ");
    Serial.print(estresse, 1);
    Serial.print(" | Aproximacoes: ");
    Serial.println(aproximacoes);
    ultimoLog = agora;
  }
  delay(20);
}
