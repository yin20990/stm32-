#ifndef __LED_H__
#define __LED_H__

#include "main.h"

void LED0_ON(void);
void LED0_OFF(void);

#define LED0_TOGGLE()   HAL_GPIO_TogglePin(LED0_GPIO_Port,LED0_Pin) 


#endif
