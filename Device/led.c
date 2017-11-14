#include "led.h"

void USER_LED_Init(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  
  //RCC
  USER_LED_RCC_CLK_ENABLE();
  
  //GPIO
  GPIO_InitStruct.Pin   = USER_LED_PIN;
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
  
  HAL_GPIO_Init(USER_LED_PORT, &GPIO_InitStruct);
  
  HAL_GPIO_WritePin(USER_LED_PORT, USER_LED_PIN, GPIO_PIN_RESET); 
}

void USER_LED_On(void)
{
  HAL_GPIO_WritePin(USER_LED_PORT, USER_LED_PIN, GPIO_PIN_SET); 
}

void USER_LED_Off(void)
{
  HAL_GPIO_WritePin(USER_LED_PORT, USER_LED_PIN, GPIO_PIN_RESET); 
}

void USER_LED_Toggle(void)
{
  HAL_GPIO_TogglePin(USER_LED_PORT, USER_LED_PIN);
}
