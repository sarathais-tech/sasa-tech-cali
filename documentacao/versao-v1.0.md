# Cali V1.0 — Primeiros traços persistentes

**Status:** código publicado; compilação e comportamento ainda precisam ser testados no Wokwi.

## Novidades
A partir da V0.9, o Cali passa a ter dois valores simulados que **persistem na memória não volátil (NVS)** do ESP32:
- `afeto`: começa em 50/100. Cada carinho acrescenta 5; cada novo episódio de rotação intensa reduz 1.
- `desconfianca`: começa em 30/100. Cada carinho reduz 2; cada novo episódio de rotação intensa acrescenta 4.

Os valores ficam entre 0 e 100. Um episódio contínuo de movimento intenso só conta uma vez, evitando gravar na memória a cada ciclo do programa.

A **desconfiança influencia a chance** de o Cali escolher uma frase vilanesca durante os comentários espontâneos (por exemplo, 30 pontos = cerca de 30% por decisão). As falas continuam predefinidas; não há aprendizado de linguagem nem IA generativa.

A memória curta da V0.9, com a resposta `Agora vem carinho?`, foi mantida.

## Testar no Wokwi
1. Salve uma cópia do projeto, preservando a V0.9: https://wokwi.com/projects/478231749554255873
2. Copie [firmware/cali_v1_0.ino](../firmware/cali_v1_0.ino) para a aba `sketch.ino`. Mantenha o `diagram.json` original.
3. Inicie a simulação. Abra o **Monitor Serial** e procure a linha `Cali lembra: afeto=50 | desconfianca=30` (em uma simulação sem valores anteriores).
4. Pressione o botão uma vez. Aguarde a linha `Tracos: afeto=55 | desconfianca=28`.
5. Pare o programa e reinicie a simulação **sem apagar o armazenamento**. Verifique se os valores foram preservados. A persistência de flash simulada pode depender de como o Wokwi reinicia a instância: teste em hardware real antes de garantir esse comportamento.
6. Faça uma rotação intensa e confira se afeto diminui 1 e desconfiança cresce 4 uma vez por episódio.
7. Repita os testes de proximidade, carinho, tontura, irritação e comentários maliciosos.

## Limites
- Os traços não representam sentimentos reais nem aprendizagem aberta.
- Ainda não há memória de fatos ensinados, reconhecimento de fala, IA de linguagem ou voz.
- A NVS guarda apenas os dois números; ampliar memória social será uma etapa futura.
- Falas pseudorrandômicas não garantem uma distribuição observável em poucos segundos.
- O HC-SR04 convencional exige adaptação de 5 V para os GPIO de 3,3 V no hardware físico.
