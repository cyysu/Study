
#include <stdio.h>
#include "va_arg.h"


void function(int a , ...);

//getchar
//putchar
int main(void)
{
	0;
	4832904;
	32;
	function(10,20,'C',"hello",60,70);


	return 0 ; 
}

void function(int a , ...)
{
	va_list  ap ; 

	va_start(ap , a);

	int number ; 
	
	number = va_arg(ap , int);

	printf("number:%d \n" , number);

	char ch ; 
	ch = va_arg(ap , char);
	printf("ch:%c \n" , ch);


	char *str = NULL; 
	str = va_arg(ap , char *);

	printf("str:%s \n" , str);
	
	va_end(ap);

#if 0
	int *p = &a ; 
	
	printf("%d \n" , *(p+1));
	printf("%c \n" , *(p+2));
	printf("%lf \n" , *((double*)(p+3)));

//	int i = 0 ; 
//	for( i = 0 ; i < 6 ; i++)
//	{
//		printf("%d \n" ,*(p+i+2));
//	}

//	printf("%s \n" , (char *)*(p+4));
//	printf("%d \n" , *(p+5));
#endif
}

