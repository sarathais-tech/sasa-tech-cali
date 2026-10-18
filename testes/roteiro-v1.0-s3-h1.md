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
