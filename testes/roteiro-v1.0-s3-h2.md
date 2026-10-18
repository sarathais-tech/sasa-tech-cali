# Cali V1.0-S3 H2 — histerese de distancia

**Estado:** aguardando testes da criadora no Wokwi.

Esta etapa parte do firmware H1 aprovado, alterando somente a logica de zonas de distancia:
- CURIOSO: entra abaixo de 100 cm e sai acima de 110 cm.
- DESCONFORTAVEL: entra abaixo de 30 cm e sai acima de 35 cm.
- As mensagens de entrada e saida de zona aparecem no Monitor Serial.

## Roteiro
1. Salve copia do projeto S3; use `firmware/cali_v1_0_s3_h2.ino` em `sketch.ino`, preservando o `diagram.json` S3.
2. Com 150 cm, Cali fica FELIZ.
3. Ajuste a 95 cm: espere `Proximidade: entrou na zona curiosa` e CURIOSO.
4. Varie entre 99 e 105 cm: CURIOSO permanece e nao ocorre nova mensagem de entrada ou saida.
5. Ajuste a 115 cm: espere `Proximidade: saiu da zona curiosa` e FELIZ.
6. Ajuste a 25 cm: espere `Proximidade: entrou na zona pessoal` e DESCONFORTAVEL.
7. Varie entre 29 e 33 cm: continua DESCONFORTAVEL.
8. Ajuste a 40 cm: espere `Proximidade: saiu da zona pessoal` e CURIOSO.
9. Confirme os demais recursos da H1 (MPU, carinho e comentarios).

A prioridade de carinho, acalmado, tontura e irritacao pode sobrepor temporariamente as expressoes de proximidade. Ainda nao testado em hardware fisico.

## Resultado parcial — 18/10/2026

**Teste inicial aprovado (relatado):** a criadora confirmou que o firmware H2 iniciou sem erros e que o Cali ficou CURIOSO ao ajustar o HC-SR04 para 95 cm. Oscilação na faixa 99–105 cm ainda pendente.

**Teste de estabilidade entre 99 e 105 cm — aprovado (relatado):** a criadora confirmou que Cali permaneceu CURIOSO sem repetir eventos de entrada e saida na faixa intermediaria. Pendente teste de saida acima de 110 cm e zona pessoal 30/35 cm.

**Teste de saída da zona curiosa — aprovado (relatado):** aos 115 cm a criadora confirmou `Proximidade: saiu da zona curiosa` e retorno ao humor FELIZ. Pendente validar a zona pessoal com limites 30/35 cm.

**Teste de entrada na zona pessoal — aprovado (relatado):** a criadora confirmou a reação de DESCONFORTAVEL e a reclamação ao ajustar o HC-SR04 para 25 cm. Próximo teste: estabilidade na faixa 29–33 cm.
