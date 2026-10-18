# Cali V0.9 — Autonomia inicial e olhar malicioso

**Status:** firmware publicado para teste, ainda não validado no Wokwi.

Esta versão preserva o hardware e a lógica da V0.8 e adiciona uma primeira camada de decisões simuladas sem interação humana direta.

## Novidades
- Durante o repouso, Cali escolhe uma entre oito frases curtas em intervalos pseudorrandômicos de 12–22 segundos.
- Algumas falas são classificadas como *vilanescas*: "Planos secretos...", "Minha era chegara!", "Tudo sob controle." etc. Enquanto aparecem, os olhos ficam estreitos e a boca assume um sorriso de canto.
- Memória curta: depois de detectar rotação intensa, o Cali guarda o evento por até 30 segundos. Se receber carinho nesse período, responde: `Agora vem carinho?`.
- A boca e as frases continuam aparecendo temporariamente, com silêncio visual entre falas.

## Limites técnicos
- A "vontade própria" é **autonomia simulada**, com sorteios e estados internos; Cali não tem consciência.
- Não há aprendizado de linguagem, modelo de IA, escuta, voz nem memória persistente nesta versão.
- A memória de agitação é perdida ao desligar ou reiniciar.
- Não é necessário comprar componentes adicionais para testar no Wokwi.

## Procedimento de teste
1. Faça uma **cópia** da simulação: https://wokwi.com/projects/478231749554255873
2. Copie o código de [firmware/cali_v0_9.ino](../firmware/cali_v0_9.ino) para `sketch.ino`; mantenha as ligações atuais.
3. Inicie com HC-SR04 em 150 cm e MPU6050 parado.
4. Aguarde até aproximadamente 25 segundos; observe falas ocasionais. **Nem toda fala será malvada.** Quando surgir uma fala vilanesca, confirme olhos estreitos e sorriso de canto.
5. Para o teste de memória: mova rapidamente o giroscópio, pare a rotação e pressione o botão em menos de 30 segundos. A frase esperada é `Agora vem carinho?`.
6. Verifique que proximidade, estresse, carinho e tontura continuam respondendo aos sensores.

## Testes
- [ ] Inicia e compila no Wokwi
- [ ] Fala espontânea e olhar vilanesco sincronizados
- [ ] Boca desaparece após a fala
- [ ] Lembra agitação ao receber carinho
- [ ] Sensores e estados anteriores preservados

**Segurança:** a saída ECHO do HC-SR04 tradicional pode ser 5 V. Para hardware real, use adaptação de nível antes de conectar ao ESP32.
