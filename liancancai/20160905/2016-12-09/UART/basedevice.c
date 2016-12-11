
#include "basedevice.h"

void __div0(void)
{
	for(;;)
		; //nothing
}
void Led_On(void)
{
	GPM4DAT &= ~0xF ; 
	//extern int _start(void);
	//_start();
}
void Led_Off(void)
{
	GPM4DAT |= 0xF ; 
}
void Buzzer_On(void)
{
	GPD0DAT |= 0x1 ; 
}
void Buzzer_Off(void)
{
	GPD0DAT &= ~0x1 ; 
}
//0-3 具体读取某个按键值  -1 就读取全部
//返回按键值
unsigned int Key_Status(int key)
{
	if((key < -1) || (key > 3))
		return 0xF;

	if(key == -1)
	{
		return (GPX3DAT>>2)&0xF;
	}else
	{
		return (GPX3DAT>>2)&(0x1<<key) ; 
	}
	return 0xF ; 
}

void Key_Configure(void)
{
	GPX3CON &= ~(0xFFFF<<8) ; 
}

void Led_Configure(void)
{
	GPM4CON &= ~0xFFFF ; 
	GPM4CON |= 0x1111 ; 
	
	//set default
	Led_Off();
}

void Buzzer_Configure(void)
{
	GPD0CON &= ~0xF ; 
	GPD0CON |= 0x1 ; 
	
	//set default
	Buzzer_Off();
}
void delay_ASM(void)
{
	__asm__ __volatile__ (
	"ldr	r0 , =0x7FFFFFF   \n"

	"delay_asm:  			  \n"
	"subs	r0 , #1 		  \n"
//	"cmp	r0 , #0 		  \n"
	"bne	delay_asm		  \n"
	);
}
//string
void delay_C(void)
{
	unsigned int val = 0xFFFFF ; 
	while(val--)
		; //nothing
}


