#include "led.h"

void LED_toggle(void) {
    gpio_toggle(LED_PORT, LED_PIN);
}
