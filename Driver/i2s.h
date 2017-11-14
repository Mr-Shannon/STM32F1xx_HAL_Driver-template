#ifndef __I2S_H__
#define __I2S_H__

#include "stm32f1xx.h"

#define USER_I2S                              SPI2
#define USER_I2S_GPIO_AF                      GPIO_AF5_SPI1
#define USER_I2S_ENABLE(a)                    __HAL_I2S_ENABLE(a)
#define USER_I2S_DISABLE(a)                   __HAL_I2S_DISABLE(a)
#define USER_I2S_RCC_CLK_ENABLE()             __HAL_RCC_SPI1_CLK_ENABLE()
#define USER_I2S_RCC_CLK_DISABLE()            __HAL_RCC_SPI1_CLK_DISABLE()


#define USER_I2S_SCK_PORT                     GPIOB
#define USER_I2S_SCK_PIN                      GPIO_PIN_13
#define USER_I2S_SCK_RCC_CLK_ENABLE()         __HAL_RCC_GPIOB_CLK_ENABLE()
#define USER_I2S_SCK_RCC_CLK_DISABLE()        __HAL_RCC_GPIOB_CLK_DISABLE()

#define USER_I2S_SD_PORT                      GPIOB
#define USER_I2S_SD_PIN                       GPIO_PIN_15
#define USER_I2S_SD_RCC_CLK_ENABLE()          __HAL_RCC_GPIOB_CLK_ENABLE()
#define USER_I2S_SD_RCC_CLK_DISABLE()         __HAL_RCC_GPIOB_CLK_DISABLE()

#define USER_I2S_WS_PORT                      GPIOB
#define USER_I2S_WS_PIN                       GPIO_PIN_12
#define USER_I2S_WS_RCC_CLK_ENABLE()          __HAL_RCC_GPIOB_CLK_ENABLE()
#define USER_I2S_WS_RCC_CLK_DISABLE()         __HAL_RCC_GPIOB_CLK_DISABLE()

#define USER_I2S_TX_DMA_CHANNEL                DMA1_Channel5
#define USER_I2S_DMA_RCC_CLK_ENABLE()         __HAL_RCC_DMA1_CLK_ENABLE()
#define USER_I2S_DMA_RCC_CLK_DISABLE()        __HAL_RCC_DMA1_CLK_DISABLE()

#define USER_I2S_AUDIO_FREQ                   I2S_AUDIOFREQ_16K



void USER_I2S_Init(void);


#endif

