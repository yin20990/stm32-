#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "main.h"

void MOTOR_Init(void);

void MOTOR_SetLeftSpeed(int8_t speed);
void MOTOR_SetRightSpeed(int8_t speed);

void Car_Stop(void);
void Go_Back(void);
void Go_Ahead(void);

//×ªÏò
void Self_Left(void);
void Self_Right(void);
void Turn_Right(void);
void Turn_Left(void);
#endif
