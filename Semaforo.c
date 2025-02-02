#include "pico/stdlib.h"
#include <stdio.h>

#define LED_VERMELHO_PIN 11
#define LED_AMARELO_PIN 12
#define LED_VERDE_PIN 13

typedef enum {
    VERMELHO,
    AMARELO,
    VERDE
} TrafficLightState;

TrafficLightState currentState = VERMELHO;

bool repeating_timer_callback(struct repeating_timer *t) {
    switch (currentState) {
        case VERMELHO:
            gpio_put(LED_VERMELHO_PIN, 0);    // Apaga o LED vermelho
            gpio_put(LED_AMARELO_PIN, 1);     // Acende o LED amarelo
            currentState = AMARELO;
            break;
        case AMARELO:
            gpio_put(LED_AMARELO_PIN, 0);     // Apaga o LED amarelo
            gpio_put(LED_VERDE_PIN, 1);       // Acende o LED verde
            currentState = VERDE;
            break;
        case VERDE:
            gpio_put(LED_VERDE_PIN, 0);       // Apaga o LED verde
            gpio_put(LED_VERMELHO_PIN, 1);    // Acende o LED vermelho
            currentState = VERMELHO;
            break;
    }
    return true;
}

int main() {
    stdio_init_all();

    // Inicializa e configura os pinos dos LEDs como saída
    gpio_init(LED_VERMELHO_PIN);
    gpio_set_dir(LED_VERMELHO_PIN, GPIO_OUT);
    
    gpio_init(LED_AMARELO_PIN);
    gpio_set_dir(LED_AMARELO_PIN, GPIO_OUT);
    
    gpio_init(LED_VERDE_PIN);
    gpio_set_dir(LED_VERDE_PIN, GPIO_OUT);

    // Inicializa o semáforo com o LED vermelho aceso
    gpio_put(LED_VERMELHO_PIN, 1);
    gpio_put(LED_AMARELO_PIN, 0);
    gpio_put(LED_VERDE_PIN, 0);

    // Configura o temporizador para chamar a função de callback a cada 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        // Imprime o estado atual do semáforo a cada segundo
        switch (currentState) {
            case VERMELHO:
                printf("Estado atual do semáforo: VERMELHO\n");
                break;
            case AMARELO:
                printf("Estado atual do semáforo: AMARELO\n");
                break;
            case VERDE:
                printf("Estado atual do semáforo: VERDE\n");
                break;
        }
        sleep_ms(1000);
    }

    return 0;
}