# Conferência do sketch original — V0.6

O código `sketch.ino` enviado pela criadora foi comparado com o arquivo [firmware/cali_v0_6.ino](../firmware/cali_v0_6.ino).

## Resultado
- O firmware versionado preserva a **mesma lógica funcional** do sketch enviado: expressões, giroscópio, estresse, botão com debounce, ultrassônico, prioridades dos estados e logs.
- O título na inicialização foi atualizado de **BUDDY V0.6** para **CALI V0.6**.
- O log `Buddy ficou incomodado!` foi atualizado para `Cali ficou incomodado!`.
- Foram reformatados comentários, recuos e quebras de linha.
- A montagem enviada em `diagram.json` confere com os GPIO usados pelo sketch.
- **Esta conferência é textual:** ainda é necessário executar a simulação com o código do repositório para validar a compilação e as reações no Wokwi.

## Observações
O texto enviado pelo chat contém escapes e realces Markdown, como `\\#include`, `**Wire**` e `\\*`. Esses caracteres são formatação da mensagem, **não devem ser copiados literalmente** para um arquivo `.ino`. O arquivo versionado contém sintaxe C++ normal.

A versão atual mede intensidade de **rotação** pelo giroscópio; não calcula a intensidade de deslocamento linear pelo acelerômetro.

Para montagem física, o pino ECHO do HC-SR04 convencional requer adaptação de 5 V para nível compatível com o ESP32.
