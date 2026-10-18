# Cali V1.0-S3 H3 — expressões persistentes

**Status:** código publicado, aguardando teste no Wokwi.

Origem: H2. A lógica dos sensores, personalidade, NVS, histerese e comandos seriais foi mantida. Apenas o desenho da boca foi alterado.

## Como testar

1. Faça cópia da simulação anterior no Wokwi.
2. Substitua **somente** o `sketch.ino` por `firmware/cali_v1_0_s3_h3.ino`.
3. Deixe distância em 25 cm, sem tocar no MPU6050 nem no botão. Aguarde 3 segundos: a fala deve sumir, mas a **boca emburrada continua** enquanto a distância for menor que 35 cm.
4. Mude para 33 cm: continua emburrado (histerese H2). Com 40 cm: o desconforto acaba e o Cali fica curioso.
5. Teste giro elevado e irritação: enquanto o humor TONTO ou IRRITADO estiver ativo, a boca fica visível mesmo em silêncio.
6. Aperte o botão: CARINHO e ACALMADO exibem boca estática em silêncio.
7. Em FELIZ e CURIOSO, silêncio continua com só os olhos; frases temporárias continuam exibindo boca animada e legenda.

## Monitor Serial

Não foram criadas novas mensagens seriais. O resultado principal é **visual**. Os logs de distância, personalidade e entrada/saída das zonas continuam como na H2.

**Nota:** se o Cali não mostrar a cara emburrada após o texto sumir, envie uma captura do OLED e dos logs de distância. Montagem física ainda não testada.

## Resultado parcial — 18/10/2026

**Aprovado (relatado):** a criadora confirmou que, a 25 cm, a expressão emburrada permanece depois de a legenda desaparecer. Ainda pendem testes das demais expressões e regressões da H2.

**Observacao de limite (relatada):** ao ajustar a distancia para 35 cm, a criadora viu Cali ficar CURIOSO. Como a saida da zona pessoal usa `distancia > 35`, sera conferido o valor efetivo exibido no Monitor Serial, com testes em 33, 35 e 36 cm, antes de alterar o firmware. A estabilidade no limite ainda nao esta aprovada.

**Causa identificada:** quando a interface Wokwi estava ajustada para 35 cm, o Monitor Serial mostrou `Distancia: 35.3`. Como a regra de saída é `distancia > 35`, o retorno ao estado CURIOSO corresponde ao valor realmente medido. Nenhuma alteração de firmware necessária por essa observação. Ainda verificar a permanência em 33 cm.

**Teste em 33 cm — aprovado (relatado):** depois de entrar na zona pessoal a 25 cm, a criadora confirmou que a boca emburrada continuou visível ao afastar para 33 cm. A leitura de 35,3 cm já explica a saída observada anteriormente no limite configurado de 35 cm. Pendente confirmação de saída da zona pessoal em 40 cm e regressões das demais expressões.
