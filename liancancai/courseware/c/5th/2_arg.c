#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

int test(int a, ...)
{
	int sum = 0, tmp;
	va_list p;

	va_start(p, a);
	sum += a;

	while(1)
	{
		tmp = va_arg(p, int);
		if (tmp == 0)
		{
			break;
		}
		sum += tmp; 
	}
    /*
	 *while(1)
	 *{
	 *    [>tmp = va_arg(p, int);<]
	 *    if (va_arg(p, int) == 0)
	 *    {
	 *        break;
	 *    }
	 *    sum += va_arg(p,int); 
	 *}
     */
	va_end(p);
	return sum;
}
int main(void)
{
	
	printf("test = %d\n", test(1,2,3,4,5, 0));
	printf("test = %d\n",test(1,2,3, 0));
	printf("test = %d\n", test(12,34,56,78,0));
	return 0;
}
