#include "uart.h"

UART_HandleTypeDef   huart1;

void USER_UART_Init(void)
{
  huart1.Instance          = USER_UART;
  HAL_UART_DeInit (&huart1);
  huart1.Init.BaudRate     = 115200;
  huart1.Init.WordLength   = UART_WORDLENGTH_8B;
  huart1.Init.StopBits     = UART_STOPBITS_1;
  huart1.Init.Parity       = UART_PARITY_NONE;
  huart1.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
  huart1.Init.Mode         = UART_MODE_TX_RX;
  HAL_UART_Init(&huart1);
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  
  if(huart->Instance == USER_UART)
  {
    //RCC
    USER_UART_TX_RCC_CLK_ENABLE(); 
    USER_UART_RX_RCC_CLK_ENABLE();
    USER_UART_RCC_CLK_ENABLE();    

    //GPIO
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pin       = USER_UART_TX_PIN;
    HAL_GPIO_Init(USER_UART_TX_PORT, &GPIO_InitStruct);
    
    GPIO_InitStruct.Mode      = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull      = GPIO_NOPULL;
    GPIO_InitStruct.Pin       = USER_UART_RX_PIN;
    HAL_GPIO_Init(USER_UART_RX_PORT, &GPIO_InitStruct);
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
  if(huart->Instance == USER_UART)
  {
    USER_UART_RCC_CLK_ENABLE(); 
    
    HAL_GPIO_DeInit(USER_UART_TX_PORT, USER_UART_TX_PIN);
    HAL_GPIO_DeInit(USER_UART_RX_PORT, USER_UART_RX_PIN);
  }
}

int fputc(int ch, FILE *f)   //Printf
{
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
  
  return ch;
}


