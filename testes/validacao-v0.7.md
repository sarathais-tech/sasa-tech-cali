# Validação funcional — Cali V0.7

Data do registro: 18/10/2026.

Ambiente: simulador Wokwi — https://wokwi.com/projects/478231749554255873

| ID | Cenário | Resultado informado pela criadora | Status |
|---|---|---|---|
| T01 | Inicialização com olhos e saudação `Ola, mamae Sasa!` | A saudação apareceu | Aprovado (relatado) |
| T02 | HC-SR04 configurado para 60 cm, expressão curiosa e alternância de frases após ~4 segundos | A criadora confirmou que funcionou e que as frases mudaram | Aprovado (relatado) |
| T03 | Proximidade abaixo de 30 cm: falas `Espaco pessoal!` e `Muita intimidade!` | Com sensor fixo em 15 cm por 10 segundos, a criadora confirmou alternância entre as duas falas | Aprovado (relatado) |
| T04 | Giroscópio: olhos `@ @` e falas de tontura | A criadora confirmou a reação ao mover o giroscópio e as reclamações | Aprovado (relatado) |
| T05 | Botão de carinho e expressão de alívio | A criadora confirmou os olhos de carinho seguidos dos olhos relaxados | Aprovado (relatado) |
| T06 | Estresse e irritação, incluindo fala `Exijo respeito!` | A criadora confirmou o estado irritado e a frase | Aprovado (relatado) |

Os resultados acima são observações relatadas pela criadora na execução da simulação, não logs capturados automaticamente.

Observação para T03: após modificar a distância, aguardar o estado anterior terminar; carinho, alívio, tontura e irritação têm prioridade sobre desconforto.

## Conclusão

Os seis cenários foram aprovados conforme relatos de execução no Wokwi. A V0.7 está funcional no ambiente simulado conforme essa bateria inicial; faltam ensaios físicos, testes de borda e validação de longa duração.
