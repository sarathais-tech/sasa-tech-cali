# Cali V0.7 — Personalidade e diálogos contextuais

## Objetivo
Introduzir frases curtas que variam conforme o humor do Cali, mantendo o circuito e os sensores da versão V0.6.

## Alterações
- Nome de inicialização: **CALI V0.7**.
- Duas frases predefinidas para cada estado (feliz, curioso, tonto, irritado, carinho, acalmado, desconfortável).
- A frase muda quando o humor muda e pode alternar a cada 4 segundos.
- O monitor serial registra `Cali diz: ...`.
- Continua sendo um sistema **baseado em regras**, sem IA generativa, reconhecimento de voz ou memórias permanentes.

## Como testar no Wokwi
1. Abra https://wokwi.com/projects/478231749554255873.
2. **Salve uma cópia/versão** antes de trocar o sketch, preservando a V0.6.
3. Abra o arquivo [firmware/cali_v0_7.ino](../firmware/cali_v0_7.ino) neste repositório.
4. Copie seu conteúdo para a aba `sketch.ino` no Wokwi. **Não altere o `diagram.json`.**
5. Execute e observe a faixa de texto na parte inferior da tela OLED.
6. Teste: sem movimento; sensor em 60 cm e 15 cm; botão; giroscópio; movimentos repetidos.
7. Espere quatro segundos no mesmo humor para observar a segunda frase.
8. Abra o monitor serial para verificar as frases também no log.

## Observações
- Não é conversação livre: o Cali escolhe frases de uma lista conforme sensores e regras.
- Nem todos os eventos têm prioridade igual: carinho > alívio > tontura > irritação > proximidade.
- Em um OLED 128 × 64 com fonte padrão tamanho 1, frases longas podem ultrapassar a largura; por isso as frases foram mantidas curtas.
- **Status: código publicado, ainda não compilado/testado no Wokwi após a alteração.** A validação prática será registrada depois do teste pela criadora.

## Próximos passos
Tornar os diálogos menos repetitivos, adicionar tempos e intensidade de interações e introduzir estados persistentes cuidadosamente.
