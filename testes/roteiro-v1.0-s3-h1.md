# Cali V1.0-S3 — etapa H1: histerese de agitação

**Estado:** código publicado; aguardando teste no Wokwi.

Modificação única: o episódio começa com `movimento > 1.5` e só termina com `movimento < 1.0`. As mudanças de traços continuam ocorrendo uma vez por episódio. A leitura `movimento` é filtrada; o valor do giroscópio no Wokwi pode não corresponder imediatamente ao valor interno.

## Roteiro
1. Salve uma cópia do projeto Wokwi ESP32-S3 anterior.
2. Cole o conteúdo de `firmware/cali_v1_0_s3_h1.ino` no sketch, sem mexer no diagrama.
3. Inicie a simulação e abra o Monitor Serial.
4. Aumente a rotação do MPU6050 até ultrapassar o limiar de 1.5. Espere `Agitacao: episodio iniciado` e **uma única** linha de atualização dos traços (`afeto -1`, `desconfianca +4`).
5. Mantenha a rotação elevada por alguns segundos: não devem ocorrer novas atualizações dos traços por agitação.
6. Reduza para um valor intermediário por volta de 1.2: o episódio deve permanecer ativo, sem nova atualização de traços.
7. Reduza abaixo de 1.0: espere `Agitacao: episodio encerrado`.
8. Agite novamente acima de 1.5: espere outro episódio iniciado, com outra atualização de traços.

**Não confundir:** `Tracos:` também aparece quando se aperta o botão de carinho; para testar a histerese, evite apertá-lo durante o teste. Ainda não foi feita compilação independente nem teste de hardware físico.

## Resultado parcial — 18/10/2026

A criadora confirmou que o firmware H1 iniciou sem erros e que a mensagem `Agitacao: episodio iniciado` apareceu ao movimentar o MPU6050. Teste de episódio contínuo e encerramento ainda pendentes.

**Teste de movimento contínuo — aprovado (relatado):** a criadora confirmou que manter a rotação alta por aproximadamente 10 segundos não gerou novos episódios nem atualizações repetidas de traços. Restam a confirmação da faixa intermediária, do encerramento abaixo de 1.0 e de um novo episódio.
