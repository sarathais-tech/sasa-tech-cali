# Roteiro de testes — Cali V0.6 (Wokwi)

| Teste | Procedimento | Esperado |
|---|---|---|
| Inicialização | Iniciar simulação | Mensagem do Cali e depois olhos |
| Repouso | Sem movimento e distância de 150 cm | Olhos felizes piscando |
| Curiosidade | HC-SR04 em 60 cm | Olhos curiosos; “Quem esta ai?” |
| Desconforto | HC-SR04 em 15 cm | “Espaco pessoal!” quando sem estado prioritário |
| Tontura | Elevar giroscópio acima do limiar | Olhos “@” por um período |
| Irritação | Sustentar rotações repetidas | Estresse cresce; expressão irritada |
| Carinho | Pressionar GPIO 18 | Corações por 2s, “Ufa...” por 3s; -30 estresse |
| Recuperação | Parar movimento | Estresse cai lentamente |

**Evidências relatadas:** olhos, expressões, MPU-6050, carinho e desconforto a 2 cm foram observados em simulação. Os outros cenários permanecem a confirmar individualmente com registros.

**Melhorias de teste:** medir falsos positivos na distância, implementar histerese entre faixas e testar circuito físico antes de uso vestível.
