
#include <stdio.h>
#include <stdarg.h>


void function(int a , ...);

int main(void)
{

	function(10,20,3.33,"hello",50,60,70);


	return 0 ; 
}

void function(int a , ...)
{
#if 0
      #include <stdarg.h>

       void va_start(va_list ap, last);
       type va_arg(va_list ap, type);
       void va_end(va_list ap);
#endif
	va_list ap ; 
		
	va_start(ap , a);

	int number ; 
	
	number = va_arg(ap , int);

	printf("number:%d \n" , number);

	double f ; 
	f = va_arg(ap , double);

	printf("f:%lf \n" , f);

	char *str = NULL; 
	str = va_arg(ap , char *);

	printf("str:%s \n" , str);

	va_end(ap);
}

