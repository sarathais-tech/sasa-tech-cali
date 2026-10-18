#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <math.h>

// SASA TECH - CALI V0.6 (antes chamado Buddy)
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
      tela.setCursor(30, 54); tela.print("Quem esta ai?");
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
      tela.setCursor(15, 53); tela.print("Espaco pessoal!");
      break;
    case CARINHO:
      tela.fillRoundRect(30, 15, 24, 29, 9, WHITE);
      tela.fillRoundRect(74, 15, 24, 29, 9, WHITE);
      tela.setCursor(47, 53); tela.print("<3 <3");
      break;
    case ACALMADO:
      tela.drawLine(30, 28, 42, 33, WHITE);
      tela.drawLine(42, 33, 54, 28, WHITE);
      tela.drawLine(74, 28, 86, 33, WHITE);
      tela.drawLine(86, 33, 98, 28, WHITE);
      tela.setCursor(47, 53); tela.print("Ufa...");
      break;
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
  tela.setCursor(35, 40); tela.print("CALI V0.6");
  tela.display();
  delay(1500);
  ultimoCiclo = millis();
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
