#include "pico/stdlib.h"
#include <FreeRTOS.h>
#include <stdio.h>
#include <task.h>

const int LED_PIN_R = 4;
const int LED_PIN_G = 6;

void led_1_task(void *p) {
    gpio_init(LED_PIN_R);
    gpio_set_dir(LED_PIN_R, GPIO_OUT);

    int delay = 250;
    while (true) {
        gpio_put(LED_PIN_R, 1);
        vTaskDelay(pdMS_TO_TICKS(delay));
        gpio_put(LED_PIN_R, 0);
        vTaskDelay(pdMS_TO_TICKS(delay));
    }
}

void led_2_task(void *p) {
    gpio_init(LED_PIN_G);
    gpio_set_dir(LED_PIN_G, GPIO_OUT);

    int delay = 250;
    while (true) {
        gpio_put(LED_PIN_G, 1);
        vTaskDelay(pdMS_TO_TICKS(delay));
        gpio_put(LED_PIN_G, 0);
        vTaskDelay(pdMS_TO_TICKS(delay));
    }
}

int main() {
    stdio_init_all();
    printf("Start RTOS \n");
    xTaskCreate(led_1_task, "LED_Task 1", 256, NULL, 1, NULL);
    xTaskCreate(led_2_task, "LED_Task 2", 256, NULL, 1, NULL);
    vTaskStartScheduler();

    while (true)
        ;
}