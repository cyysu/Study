
#include <stdio.h>

//putchar();
int myprintf(const char *fmt , ...);

int main(void)
{


	myprintf("hello %d %c %x %o %s \n" , 255 , 'C' , 255 ,255, "kitty");


	return 0 ; 
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

