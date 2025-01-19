
# 🚀 Controle de Teclado Matricial 4x4 com Raspberry Pi Pico W

Este projeto demonstra como integrar um teclado matricial 4x4 com um Raspberry Pi Pico W para detectar entradas de teclas e acionar LEDs RGB e um buzzer com base nas teclas pressionadas.

## Link do Vídeo Ensaio

[Demonstração de Funcionamento do Projeto](https://www.youtube.com/watch?v=-MSzEE1RgBY)

## Descrição

O projeto utiliza um teclado matricial 4x4 conectado ao Raspberry Pi Pico W para capturar entradas do usuário. Dependendo da tecla pressionada, diferentes LEDs RGB são acionados ou um buzzer emite um som específico. 
#### Exemplo 
Ao pressionar a tecla 'A', o LED vermelho acende; ao pressionar '#', o buzzer toca uma nota de 200 Hz por 500 ms.

## Materiais Necessários

- Raspberry Pi Pico W
- Teclado matricial 4x4
- LEDs RGB (Vermelho, Verde e Azul)
- Buzzer
- Resistores adequados para os LEDs
- Jumpers
- Placa BitDogLab ou Protoboard
  
## Esquema de Ligação

A tabela abaixo descreve as conexões entre o Raspberry Pi Pico W e os componentes:

Componente	Pino do Pico	Função
```
ROW1	GP9	Linha 1
ROW2	GP8	Linha 2
ROW3	GP7	Linha 3
ROW4	GP6	Linha 4
COL1	GP5	Coluna 1
COL2	GP4	Coluna 2
COL3	GP3	Coluna 3
COL4	GP2	Coluna 4
LED1_R	GP13	LED Vermelho
LED1_G	GP11	LED Verde
LED1_B	GP12	LED Azul
BUZZER	GP21	Buzzer
```

Certifique-se de conectar os pinos correspondentes do teclado matricial às GPIOs designadas no Raspberry Pi Pico W.

## Código Fonte

O código fonte completo está disponível no repositório. Ele inclui funções para configurar os pinos GPIO, detectar qual tecla foi pressionada no teclado matricial, acionar os LEDs correspondentes e gerar tons no buzzer.

## Como Executar

#### Configuração do Ambiente de Desenvolvimento:

- Instale o SDK do Raspberry Pi Pico W.

#### Compilação do Código:

- Clone este repositório em sua máquina local.
- Navegue até o diretório do projeto e compile o código utilizando as ferramentas fornecidas pelo SDK.

#### Upload para o Raspberry Pi Pico W:

- Conecte o Raspberry Pi Pico W ao seu computador via USB.
- Carregue o firmware compilado para o Pico W seguindo as instruções do SDK.

#### Execução:

Após o upload, o programa será executado automaticamente.
Pressione as teclas no teclado matricial para acionar os LEDs e o buzzer conforme programado.

## Licença

Este programa foi desenvolvido como um exemplo educacional e pode ser usado livremente para fins de estudo e aprendizado.

## Autores

- LORENZO GIUSEPPE OLIVEIRA BARONI
- LUIZ VICTOR RIBEIRO SANTOS
- MARY NICOLE DE SOUSA MENDES
- ÍTALO ALVES TENÓRIO DE ALMEIDA
- JOÃO PEDRO FERREIRA DE JESUS
- JOÃO PAULO SANTOS LUZ PEREIRA
- FELIPE SILVA QUEIROZ
