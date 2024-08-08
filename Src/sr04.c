#include "sr04.h"
#include "motor.h"
#include "servo.h"
#include "oled.h"

uint32_t distance_cm = 0;


void Trigger_signal(void)
{
		Trigger_ON();							
		HAL_Delay(15);						
		Trigger_OFF();	
} 

void SR04_control()
{
	OLED_ShowNum(38,10,distance_cm,sizeof(distance_cm),9);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{	
		static uint32_t time_us = 0;
	
		if(GPIO_Pin == GPIO_PIN_14)
		{
				if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_14))
				{
						HAL_TIM_Base_Start(&htim4);									
						__HAL_TIM_SetCounter(&htim4,0);								
				}
				else if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_14) == 0)
				{
						HAL_TIM_Base_Stop(&htim4);									
						time_us = __HAL_TIM_GetCounter(&htim4);							
						
						distance_cm = time_us * 340/2*0.000001*100;
						SR04_control();
						time_us = 0;
				}
		}
}

