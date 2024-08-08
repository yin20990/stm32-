#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__

#include "usart.h"

void Bluetooth_Init(void);
void Bluetooth_control(uint8_t data_rx);

#endif

