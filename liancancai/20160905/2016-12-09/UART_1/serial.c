
#include "res.h"

void serial_init(void)
{
	
	//1.看底板图,找到串口,找出三根线所对应的GPIO  GPA0_0  GPA0_1
	//2.将GPIO配置成串口模式
	GPA0CON &= ~0xFF ; 
	GPA0CON |= 0x22  ; 

	//3.配置8N1
	ULCONn = 0x3 ; 
	//4.配置轮询模式  polling mode
	UCONn &= ~0xF ; 
	UCONn |= 0x5  ; 

	//4.配置波特率   整数部分  小数部分
	UBRDIVn = 53 ;   //100M/(115200*16)-1 => 53.25
	UFRACVALn = 4 ;  //0.25*16=>4
}

void putchar(char ch)
{
	while(1)
	{
		if(!(UTRSTATn&(1 << 2)))
			continue ;
		UTXHn = ch ; 
		if(ch == '\n')
			putchar('\r');
		break;
	}
}

char getchar(void)
{
	char ch ; 
	while(1)
	{
		if(!(UTRSTATn & 1))
			continue ;
		ch = URXHn ; 
		putchar(ch);
		if(ch == '\r')
			putchar('\n');
		break;
	}
	return ch ; 
}


void gets(char *buffer)
{
	char ch ; 
	while(1)
	{
		ch = getchar();
		if(ch == '\r')
			break;
		*buffer=ch ; 
		buffer++ ; 
	}
	*buffer = '\0';
}

void print_num(int num , int base)
{
	if(num == 0)
		return ; 
	print_num(num/base , base);
	putchar("0123456789ABCDEF"[num%base]);
}

void myputs(const char *str)
{
	while(*str)
	{
		putchar(*str++);
	}
}

int myprintf(const char *fmt , ...)
{
	unsigned int *Addr = (void *)&fmt ; 
	Addr++ ; 
	while(*fmt)
	{
		if(*fmt != '%')
		{
			putchar(*fmt);
			fmt++ ; 
			continue ;
		}

		//已经找到 %
		++fmt;

		switch(*fmt)
		{
			case 'd' :  print_num(*Addr++ , 10);  break;
			case 'o' :	print_num(*Addr++ , 8 );  break;
			case 'x' :	print_num(*Addr++ , 16);  break;
			case 'c' :  putchar(*Addr++); break;
			case 's' :  myputs((char *)*Addr++);    break;
			case '%' :  putchar('%');     break;
		}
		++fmt ;
	}

	return 0 ; 
}

void serial_operation(void)
{
	myprintf("****************************************\n");
	myprintf("**           WelCome To Minicom       **\n");
	myprintf("**             KAIFA0905              **\n");
	myprintf("**              KITTY                 **\n");
	myprintf("**                              12.09 **\n");
	myprintf("****************************************\n");


	char Buffer[50] ; 

	char *Command[] = {
	"led_on",
	"led_off",
	"buzzer_on",
	"buzzer_off",
	"exit",
	"reset",
	};
	#define SWRESET  *(U32 *)0x10020400

	Led_Configure();
	Buzzer_Configure();

	int i ; 
	while(1)
	{
		myprintf("KAIFA0905 #");
		gets(Buffer);
		//查找命令
		for(i = 0 ; i < ARRAY_SIZE(Command) ;i++)
		{
			if(strcmp(Buffer , Command[i]) == 0)
			{
				break;
			}
		//	myprintf("hello i:%d \n" , i);
		}
		if(*Buffer == '\0')
			continue ; 
		//判断是否有找到
		if(i == ARRAY_SIZE(Command))
			myprintf("Command Not Found! \n");
		if(i == 4)
			break;
		switch(i)
		{
		case 0: Led_On();  break;
		case 1: Led_Off(); break;
		case 2: Buzzer_On(); break;
		case 3: Buzzer_Off();break;
		case 5: SWRESET = 1 ; break;
		}
	}
}
