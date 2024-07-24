#include "motor.h"
#include "tim.h"
#include "gpio.h"

//Ê¹ÓÃTIM2£¬Ch3
//100-1£¬72-1
//PA4£¬5£¬6£¬7

void MOTOR_Init()
{
		MX_TIM2_Init();
		HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
		MX_GPIO_Init();
}

void MOTOR_SetLeftSpeed(int8_t speed)
{
		if(speed>0)
		{
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
				PWM_SET_COMPARE2(speed);
		}
		else if(speed==0)
		{
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
				PWM_SET_COMPARE2(speed);
		}
		else
		{
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
				PWM_SET_COMPARE2(-speed);
		}
}

void MOTOR_SetRightSpeed(int8_t speed)
{
		if(speed>0)
		{
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
				PWM_SET_COMPARE2(speed);
		}
		else if(speed==0)
		{
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
				PWM_SET_COMPARE2(speed);
		}
		else
		{
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
				PWM_SET_COMPARE2(-speed);
		}
}

void Turn_Left()
{
		MOTOR_SetRightSpeed(70);
		MOTOR_SetLeftSpeed(0);
}

void Turn_Right()
{
		MOTOR_SetRightSpeed(0);
		MOTOR_SetLeftSpeed(70);
}

void Self_Right()
{
		MOTOR_SetRightSpeed(-70);
		MOTOR_SetLeftSpeed(70);
}

void Self_Left()
{
		MOTOR_SetRightSpeed(70);
		MOTOR_SetLeftSpeed(-70);
}

void Car_Stop()
{
		MOTOR_SetRightSpeed(0);
		MOTOR_SetLeftSpeed(0);
}

