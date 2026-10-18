# C.A.L.I. 💗
**Companheiro Adaptativo de Linguagem e Interação**

Projeto autoral **Sasa Tech — Cali**: companheiro eletrônico interativo com ESP32, expressões em display OLED e reação a estímulos do ambiente. O Cali tem uma personalidade fictícia e um sistema de emoções **simuladas por regras**; não possui sentimentos ou consciência.

> **Estado atual:** V0.6 em simulação no Wokwi. A montagem física e a portabilidade ainda não foram validadas.

## O que já foi desenvolvido no simulador
- Olhos animados e piscadas no display OLED SSD1306 (128 × 64).
- Reação a rotação medida pelo MPU-6050: fica tonto e acumula estresse.
- Recuperação gradual do estresse e expressão de irritação.
- Botão de carinho: reduz o estresse, mostra corações e em seguida “Ufa...”.
- Sensor HC-SR04: diferencia distância normal, aproximação e objeto muito próximo.

Os testes demonstrados foram feitos em simulação, **não em hardware físico**. O sensor ultrassônico detecta obstáculos, e não identifica pessoas.

## Componentes do protótipo
| Componente | Uso |
|---|---|
| ESP32 DevKit | Processamento |
| OLED SSD1306 I²C | Expressões |
| MPU-6050 | Aceleração e rotação |
| HC-SR04 | Distância |
| Botão | Carinho / interação |
| Jumpers e protoboard | Montagem de testes |

## Ligações usadas na simulação
| Componente | Conexão ESP32 |
|---|---|
| OLED SDA / SCL | GPIO 21 / GPIO 22 |
| MPU-6050 SDA / SCL | GPIO 21 / GPIO 22 |
| OLED e MPU VCC / GND | 3V3 / GND |
| Botão | GPIO 18 e GND (INPUT_PULLUP) |
| HC-SR04 TRIG | GPIO 5 |
| HC-SR04 ECHO | GPIO 19 (somente simulação direta) |
| HC-SR04 VCC / GND | 5V / GND |

**Atenção:** o ECHO do HC-SR04 convencional pode emitir 5 V. Para conectar em ESP32 físico, use adaptação de nível para 3,3 V (por exemplo, divisor resistivo corretamente dimensionado), ou sensor compatível. Confira também a pinagem real dos módulos.

## Como reproduzir
1. Abra um projeto ESP32 no [Wokwi](https://wokwi.com/projects/new/esp32).
2. Adicione SSD1306, MPU-6050, botão e HC-SR04.
3. Monte conforme a tabela acima.
4. Adicione as bibliotecas: **Adafruit GFX Library**, **Adafruit SSD1306**, **Adafruit MPU6050** e **Adafruit Unified Sensor**.
5. Cole o conteúdo de [firmware/cali_v0_6.ino](firmware/cali_v0_6.ino) em `sketch.ino`.
6. Inicie a simulação. Altere a rotação no MPU-6050 e a distância no HC-SR04; clique no botão para oferecer carinho.

**[Abrir a simulação do Cali no Wokwi](https://wokwi.com/projects/478231749554255873)**. O conteúdo remoto ainda não foi comparado arquivo a arquivo com este repositório.

## Evolução
| Versão | Marco |
|---|---|
| V0.1 | Olhos piscando |
| V0.2 | Expressões |
| V0.3 | Movimento + estresse |
| V0.4–V0.5 | Botão de carinho + alívio |
| V0.6 | Proximidade (testes parciais no Wokwi) |
| V0.7 | Diálogos contextuais predefinidos (6 testes aprovados no Wokwi) |\n| V0.8 | Boca dinâmica e comentários ocasionais (5 testes aprovados no Wokwi) |\n| V0.9 | Olhar malicioso, comentários variados e memória curta (aguardando teste) |

## Próximos passos
- Melhorar filtragem do sensor de distância e evitar oscilações perto dos limites.
- Criar variações de frases e comportamento contextual.
- Reproduzir a montagem com componentes físicos, validando alimentação e níveis elétricos.
- Adicionar áudio local, caixa portátil e bateria com circuito apropriado.
- Futuramente, criar **Sasa Tech Connect** para cadastro voluntário, apelidos, preferências e memória social, respeitando privacidade e consentimento.

Veja [documentacao/visao-geral.md](documentacao/visao-geral.md), [testes/roteiro-v0.6.md](testes/roteiro-v0.6.md) [instruções para V0.7](documentacao/versao-v0.7.md) [instruções para V0.8](documentacao/versao-v0.8.md) e [instruções para V0.9](documentacao/versao-v0.9.md).

**Projeto em desenvolvimento.**