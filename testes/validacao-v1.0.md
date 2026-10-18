# Validação Cali V1.0 — Wokwi

Data: 18/10/2026. Resultados informados pela criadora.

| Teste | Resultado | Estado |
|---|---|---|
| Compilação e inicialização após correção da posição do `enum Humor` | A criadora confirmou que iniciou normalmente | Aprovado (relatado) |
| Alteração de afeto e desconfiança com botão | A criadora confirmou aumento do afeto e redução da desconfiança no Monitor Serial | Aprovado (relatado) |
| Persistência após Stop e Start no Wokwi | Valores voltaram a afeto=50 e desconfianca=30 | Não preservou dados entre sessões simuladas |
| Persistência após `ESP.restart()` na mesma execução | A criadora confirmou que os valores anteriores permaneceram | Aprovado (relatado) |
| Alteração dos traços com movimento | Aguardando teste | Pendente |
| Regressão das expressões da V0.9 | Aguardando teste | Pendente |

O êxito da compilação não confirma, por si só, o funcionamento da persistência NVS no Wokwi.

## Investigação de persistência

Em 18/10/2026, após pressionar Stop e depois Start, a criadora observou retorno aos valores padrão (50 e 30). A escrita em execução havia funcionado. Próximo teste: reiniciar o ESP32 dentro da mesma sessão sem encerrar a simulação para diferenciar NVS não preservada entre sessões de falha na lógica de gravação.

**Conclusão adicional:** o teste com comando serial `r` e `ESP.restart()` mostrou recuperação da NVS dentro da sessão. O comando serial foi incluído temporariamente no sketch do Wokwi pela criadora; ainda não integra o firmware principal versionado. Testar em hardware físico posteriormente.
