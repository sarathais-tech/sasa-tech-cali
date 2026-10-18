# Cali V0.8 — Boca dinâmica e falas ocasionais

**Status:** implementação publicada, aguardando teste no Wokwi.

## Comportamento
- No repouso, a tela mostra **somente os olhos**.
- Quando um novo humor é acionado, o Cali mostra **boca animada e legenda** por aproximadamente **2,5 segundos**; depois a boca e a legenda desaparecem.
- No humor FELIZ, após a inicialização, ele pode fazer comentários predefinidos sem ação direta (primeiro após ~3,5 s; depois em intervalos pseudorrandômicos de 12 a 22 s).
- Diferentes humores mostram estilos diferentes de boca.
- A boca alterna entre aberta/fechada a cada 250 ms enquanto a fala visual estiver ativa.
- Os sensores, GPIO e regras de estresse permanecem iguais aos da V0.7.

## Limites
Este comportamento é uma simulação determinística com elementos pseudorrandômicos: não há consciência, conversa livre, áudio, microfone nem IA generativa. A tela OLED não reproduz som.

## Como testar
1. Faça uma cópia do projeto em https://wokwi.com/projects/478231749554255873 para não sobrescrever a V0.7.
2. No Wokwi, substitua **apenas** o conteúdo da aba `sketch.ino` pelo código em [cali_v0_8.ino](../firmware/cali_v0_8.ino).
3. Mantenha o `diagram.json` original. A biblioteca utilizada é a mesma da V0.7.
4. Inicie a simulação e deixe o sensor de distância em 150 cm e o MPU sem rotação.
5. Após alguns segundos, verifique a saudação com boca; em seguida ela deve desaparecer.
6. Aguarde aproximadamente 12 a 22 segundos e verifique uma fala ocasional.
7. Mude o ultrassônico para 60 cm e depois 15 cm, aguardando o desaparecimento da boca em cada estado.
8. Acione o botão e mova o giroscópio: as expressões anteriores devem continuar funcionando.

## Checklist
- [ ] Compilação e inicialização
- [ ] Boca e legenda aparecem juntas
- [ ] Boca desaparece após ~2,5 s
- [ ] Comentário espontâneo em repouso
- [ ] Curiosidade e desconforto
- [ ] Botão de carinho e alívio
- [ ] Tontura e irritação

**Cuidado:** em equipamentos reais, o ECHO do HC-SR04 tradicional é 5 V; usar adaptação para o ESP32 (3,3 V).
