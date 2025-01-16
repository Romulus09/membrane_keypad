#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdio.h>

#define ROW1 9
#define ROW2 8
#define ROW3 7
#define ROW4 6

#define COL1 5
#define COL2 4
#define COL3 3
#define COL4 2

#define LED1_G 11 // LED Verde
#define LED1_B 12 // LED Azul
#define LED1_R 13 // LED Vermelho

#define BUZZER 21

// Função para configurar os pinos GPIO
void configurar_gpio() {
    // Inicializa e configura os pinos das linhas como saída
    gpio_init(ROW1);
    gpio_init(ROW2);
    gpio_init(ROW3);
    gpio_init(ROW4);
    gpio_set_dir(ROW1, GPIO_OUT);
    gpio_set_dir(ROW2, GPIO_OUT);
    gpio_set_dir(ROW3, GPIO_OUT);
    gpio_set_dir(ROW4, GPIO_OUT);

    // Inicializa e configura os pinos das colunas como entrada com pull-up
    gpio_init(COL1);
    gpio_init(COL2);
    gpio_init(COL3);
    gpio_init(COL4);
    gpio_set_dir(COL1, GPIO_IN);
    gpio_set_dir(COL2, GPIO_IN);
    gpio_set_dir(COL3, GPIO_IN);
    gpio_set_dir(COL4, GPIO_IN);
    gpio_pull_up(COL1);
    gpio_pull_up(COL2);
    gpio_pull_up(COL3);
    gpio_pull_up(COL4);

    // Inicializa e configura os pinos dos LEDs como saída
    gpio_init(LED1_G);
    gpio_init(LED1_B);
    gpio_init(LED1_R);
    gpio_set_dir(LED1_G, GPIO_OUT);
    gpio_set_dir(LED1_B, GPIO_OUT);
    gpio_set_dir(LED1_R, GPIO_OUT);

    // Inicializa e configura o pino do Buzzer como saída
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

int main()
{
    stdio_init_all();
    configurar_gpio();

}
