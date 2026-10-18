# Validação funcional — Cali V0.7

Data do registro: 18/10/2026.

Ambiente: simulador Wokwi — https://wokwi.com/projects/478231749554255873

| ID | Cenário | Resultado informado pela criadora | Status |
|---|---|---|---|
| T01 | Inicialização com olhos e saudação `Ola, mamae Sasa!` | A saudação apareceu | Aprovado (relatado) |
| T02 | HC-SR04 configurado para 60 cm, expressão curiosa e alternância de frases após ~4 segundos | A criadora confirmou que funcionou e que as frases mudaram | Aprovado (relatado) |
| T03 | Proximidade abaixo de 30 cm: falas `Espaco pessoal!` e `Muita intimidade!` | A criadora observou ambas as falas em aproximações; ainda falta confirmar alternância com a distância fixa | Parcialmente aprovado (relatado) |
| T04 | Giroscópio: tontura | Ainda não executado | Pendente |
| T05 | Botão de carinho | Ainda não executado nesta versão | Pendente |
| T06 | Estresse e irritação | Ainda não executado nesta versão | Pendente |

Os resultados acima são observações relatadas pela criadora na execução da simulação, não logs capturados automaticamente.

Observação para T03: após modificar a distância, aguardar o estado anterior terminar; carinho, alívio, tontura e irritação têm prioridade sobre desconforto.
