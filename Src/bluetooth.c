#include "bluetooth.h"
#include "motor.h"
#include "servo.h"

void Bluetooth_Init()
{
	MX_USART1_UART_Init();
	
}

void Bluetooth_control(uint8_t data_rx)
{
	if(data_rx==0x30) Car_Stop();
	if(data_rx==0x31) Go_Ahead();
	if(data_rx==0x32) Go_Back();
	if(data_rx==0x33) Turn_Left();
	if(data_rx==0x34) Turn_Right();
	if(data_rx==0x35)	Self_Left();
	if(data_rx==0x36)	Self_Right();
						
}

