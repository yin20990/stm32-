#include "tim.h"
#include "main.h"
#include "gpio.h"

void SERVO_SetAngle(uint16_t a)
{
		uint32_t t=t/180*2000;
		PWM_SET_COMPARE2(t);
}

void SERVO_Init()
{
		MX_TIM2_Init();
		MX_GPIO_Init();
		SERVO_SetAngle(0);
}
