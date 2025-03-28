#ifndef LED_H
#define LED_H

#include <libopencm3/stm32/gpio.h>

#define LED_RCC     RCC_GPIOC
#define LED_PORT    GPIOC
#define LED_PIN     GPIO13

/* Toggle the on-board LED of the BlackPill. */
void LED_toggle(void);

#endif // LED_H
