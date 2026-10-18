# Visão geral — Sasa Tech / C.A.L.I.

## Ideia
C.A.L.I. significa **Companheiro Adaptativo de Linguagem e Interação**. O objetivo é construir um pequeno companheiro eletrônico portátil, com expressões visuais, reações aos movimentos e à aproximação de objetos e interações divertidas.

## Escopo implementado
A versão V0.6 do protótipo é executada em simulação no Wokwi, com ESP32, display OLED, MPU-6050, HC-SR04 e botão. O comportamento emocional é uma **máquina de estados baseada em regras**, incluindo uma variável numérica de estresse; não é inteligência artificial autônoma.

## Funcionamento
- Uma rotação intensa provoca tontura temporária.
- Movimento prolongado eleva o estresse; o repouso reduz gradualmente esse valor.
- Botão acionado reduz estresse e apresenta expressões de carinho e alívio.
- Objeto a menos de 100 cm aciona curiosidade; abaixo de 30 cm, desconforto, exceto quando outro estado de prioridade maior prevalece.
- Novas aproximações repetidas aumentam estresse após três eventos contados numa janela de aproximadamente dez segundos.

## Limites conhecidos
- O MPU-6050 atualmente usa sobretudo a intensidade da rotação; sacudidas sem rotação podem não ser detectadas.
- O HC-SR04 mede distâncias de obstáculos à frente, não quantidade nem identidade de pessoas.
- Os estados não constituem sentimentos reais; as futuras relações serão simulações de afinidade.
- Sem microfone/alto-falante, o Cali ainda não conversa por voz.
- Não existe ainda integração com app web, identificação por celular ou bateria integrada.
- Uma protoboard com fios soltos não é indicada para ser usada presa ao peito.

## Futuro
Implementar falas gravadas, armazenamento persistente, personalidades variáveis e app de apresentação voluntária de pessoas, sem rastreamento silencioso de celulares. A identificação automática por Bluetooth dependerá de app, permissões e compatibilidade do sistema operacional.

## Segurança elétrica
O pino ECHO do HC-SR04 tradicional pode trabalhar com 5 V, acima do tolerado por GPIO do ESP32. Antes da montagem física é obrigatório adequar o nível lógico e verificar o circuito de alimentação. Baterias de lítio exigem módulos adequados de carga/proteção e não devem ser ligadas diretamente à placa sem projeto compatível.
