#ifndef __SR04_H__
#define __SR04_H__

#include "main.h"
#include "tim.h"
#include "gpio.h"

#define		Trigger_ON() 		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15,GPIO_PIN_SET)
#define		Trigger_OFF() 	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15,GPIO_PIN_RESET)

void Trigger_signal(void);
void SR04_control(void);

#endif
