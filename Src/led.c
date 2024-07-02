#include "LED.h"

void LED0_ON()
{
		HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,GPIO_PIN_RESET);
}
void LED0_OFF()
{
	HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,GPIO_PIN_SET);
}
