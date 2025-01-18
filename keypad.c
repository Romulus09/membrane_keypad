#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdio.h>

// Definição dos pinos para as linhas, colunas, leds e buzzer do teclado matricial
#define ROW1 9
#define ROW2 8
#define ROW3 7
#define ROW4 6

#define COL1 5
#define COL2 4
#define COL3 3
#define COL4 2

#define LED1_G 11 
#define LED1_B 12 
#define LED1_R 13 

#define BUZZER 21

// Vetores com os pinos das linhas e colunas
const int rows[4] = {ROW1, ROW2, ROW3, ROW4};
const int cols[4] = {COL1, COL2, COL3, COL4};

// Função para configurar os pinos GPIO
void configurar_gpio() {
    // Configura as linhas como saída
    for (int i = 0; i < 4; i++) {
        gpio_init(rows[i]);
        gpio_set_dir(rows[i], GPIO_OUT);
        gpio_put(rows[i], 1);
    }

    // Configura as colunas como entrada com pull-up
    for (int i = 0; i < 4; i++) {
        gpio_init(cols[i]);
        gpio_set_dir(cols[i], GPIO_IN);
        gpio_pull_up(cols[i]);
    }

    // Configura os LEDs como saída
    const int leds[] = {LED1_R, LED1_G, LED1_B};
    for (int i = 0; i < 3; i++) {
        gpio_init(leds[i]);
        gpio_set_dir(leds[i], GPIO_OUT);
    }

    // Configura o buzzer como saída
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_put(BUZZER, 0);
}

// Função para detectar qual tecla foi pressionada no teclado matricial
char detectar_tecla() {
    const char matriz[4][4] = {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'*', '0', '#', 'D'}
    };
    // Varre as linhas e colunas para detectar a tecla pressionada
    for (int i = 0; i < 4; i++) {
        gpio_put(rows[i], 0);
        for (int j = 0; j < 4; j++) {
            if (gpio_get(cols[j]) == 0) {
                sleep_ms(200); 
                gpio_put(rows[i], 1);
                return matriz[i][j];
            }
        }
        gpio_put(rows[i], 1); 
    }

    return '\0'; // Retorna nulo se nenhuma tecla foi pressionada
}

// Função para gerar tons no buzzer
void tone(uint buzzer, uint frequencia, uint duracao) {
    uint32_t periodo = 1000000 / frequencia; 
    uint32_t meio_periodo = periodo / 2;    
    uint32_t ciclos = frequencia * duracao / 1000;

    for (uint32_t i = 0; i < ciclos; i++) {
        gpio_put(buzzer, 1); 
        sleep_us(meio_periodo);
        gpio_put(buzzer, 0); 
        sleep_us(meio_periodo);
    }
}

// Função para acionar LEDs e o buzzer com base na tecla pressionada
void acionar_led(char tecla) {
    switch (tecla) {
        case 'A':
            gpio_put(LED1_R, 1); 
            sleep_ms(500);       
            gpio_put(LED1_R, 0); 
            break;
        case 'B':
            gpio_put(LED1_B, 1); 
            sleep_ms(500);       
            gpio_put(LED1_B, 0); 
            break;
        case 'C':
            gpio_put(LED1_G, 1); 
            sleep_ms(500);       
            gpio_put(LED1_G, 0); 
            break;
        case '#':
            tone(BUZZER, 200, 500); 
            break;
        case 'D':
            gpio_put(LED1_R, 1);
            gpio_put(LED1_G, 1);
            gpio_put(LED1_B, 1);
            sleep_ms(500); 
            
            gpio_put(LED1_R, 0);
            gpio_put(LED1_G, 0);
            gpio_put(LED1_B, 0);
            break;
        default:
            break;
    }
}

// Função principal
int main() {
    stdio_init_all(); 
    configurar_gpio(); 

    while (true) {
        char tecla = detectar_tecla(); 
        if (tecla != '\0') { 
            printf("Tecla pressionada: %c\n", tecla); 
            acionar_led(tecla); 
        }
    }

    return 0; 
}
