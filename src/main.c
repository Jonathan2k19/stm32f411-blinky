#include <stdint.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include "led.h"

/* Execute NOPs for DELAY_CYCLES cycles. */
void delay(uint32_t delay_cycles);

/* Setup clock and GPIO for the LED on board of the BlackPill. */
void setup_LED(void);

void delay(uint32_t delay_cycles) {
    for (uint32_t i = 0; i < delay_cycles; i++) {
        __asm__("nop");
    }
}

void setup_LED(void) {
    rcc_periph_clock_enable(LED_RCC);
    gpio_mode_setup(LED_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_PIN);
}

int main(void) {
    setup_LED();

    while (1) {
        LED_toggle();
        delay(1000000);
    }
}
