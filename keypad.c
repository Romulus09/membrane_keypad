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

int main()
{
    stdio_init_all();
}
