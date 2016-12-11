
#ifndef  _BASEDEVICE_H
#define  _BASEDEVICE_H

#include "res.h"

void delay_C(void);
void delay_ASM(void);
void Led_On(void);
void Led_Off(void);
void Buzzer_On(void);
void Buzzer_Off(void);
unsigned int Key_Status(int key);
void Key_Configure(void);
void Led_Configure(void);
void Buzzer_Configure(void);
void __div0(void);

#endif //_BASEDEVICE_H
