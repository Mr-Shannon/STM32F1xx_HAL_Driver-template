#ifndef __LED_H__
#define __LED_H__

#include "stm32f4xx.h"

#define USER_LED_PORT                     GPIOA
#define USER_LED_PIN                      GPIO_PIN_5
#define USER_LED_RCC_CLK_ENABLE()         __HAL_RCC_GPIOA_CLK_ENABLE()
#define USER_LED_RCC_CLK_DISABLE()        __HAL_RCC_GPIOA_CLK_DISABLE()

void USER_LED_Init(void);
void USER_LED_On(void);
void USER_LED_Off(void);
void USER_LED_Toggle(void);

#endif
