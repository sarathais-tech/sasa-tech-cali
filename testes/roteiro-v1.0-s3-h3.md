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

**Evidência de saída da zona pessoal (print do Monitor Serial, 18/10/2026):** log exibiu `Distancia: 33.4 cm`, depois `Proximidade: saiu da zona pessoal`, `Cali diz: Quem esta ai?` e `Distancia: 35.3 cm`. Confirma que a transição para CURIOSO ocorreu quando a leitura ultrapassou 35 cm; a captura não demonstra isoladamente qual distância foi selecionada no controle do simulador. Expressão visual final ainda não confirmada explicitamente.

**Transicao visual da zona pessoal para CURIOSO — aprovada (relatada):** a criadora confirmou que, ao sair da zona pessoal, a boca emburrada desapareceu e os olhos assumiram a expressao curiosa. Testes visuais de DESCONFORTAVEL concluidos. Ainda faltam verificacoes de IRRITADO, TONTO, CARINHO e ACALMADO em silencio.

**Expressao IRRITADO persistente — aprovada (relatada):** a criadora confirmou que, com estresse alto, olhos bravos e boca seria permaneceram depois que a fala sumiu. Pendente verificar TONTO, CARINHO e ACALMADO em silencio.

**Expressao TONTO — aprovada (relatada):** a criadora confirmou o aparecimento dos olhos `@ @` e da boquinha redonda durante movimento do MPU6050. A persistencia da boca apos o fim da fala nao foi demonstrada, pois o estado de tontura pode expirar antes da legenda. Pendentes testes de CARINHO e ACALMADO em silencio.

**CARINHO e ACALMADO — aprovados (relatados):** a criadora confirmou o sorriso no carinho e a expressão tranquila durante o alívio.

## Fechamento da rodada H3

Os testes visuais relatados de DESCONFORTAVEL persistente, transição para CURIOSO, IRRITADO persistente, TONTO visível, CARINHO e ACALMADO foram concluídos no Wokwi com ESP32-S3. A permanência da boca de TONTO em silêncio não foi comprovada porque a duração atual da tontura (1,8 s após movimento) é menor que a duração da fala (2,5 s). **Status: H3 validada para os comportamentos observados, com melhoria de tempo de tontura pendente.** Sem validação em hardware físico.
