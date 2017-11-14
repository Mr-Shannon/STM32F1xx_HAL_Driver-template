#include "board.h"

extern I2S_HandleTypeDef   hi2s1;

uint16_t data_buffer[512] ={0};

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  USER_UART_Init();	
  USER_I2S_Init();
  
  while(1)
  {
    HAL_Delay(100);
    printf("DMA \n");
  }
}

