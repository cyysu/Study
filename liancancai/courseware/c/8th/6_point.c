#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a = 10, b = 20;
	int* p = &a;

	p = &b;
	*p = 40;
    /*
	 *a = 20;
	 **p  = 30;
     */
	printf("&a = %p a = %d\n", &a, a);
	printf("&b = %p b = %d\n", &b, b);
	printf("&p = %p\n", &p);
	printf("p = %p\n", p);
	printf("*p = %d\n", *p);


	return 0;
}
