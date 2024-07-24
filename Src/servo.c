#include "tim.h"
#include "main.h"
#include "gpio.h"

void SERVO_SetAngle(uint16_t a)
{
		uint32_t t=a*2000/180+500;
		PWM_SET_COMPARE3(t);
}

void SERVO_Init()
{
		MX_TIM3_Init();
		HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_3);
		MX_GPIO_Init();
		SERVO_SetAngle(0);
}
