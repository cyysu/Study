#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int e;// -> ds
int ee = 123;

int main(void)
{
	static int b;
	int *p = NULL;//申请空间 -> heap
	signed int a = 123;//局部变量 -> stack
	register
	volatile

	p = &a;
	p = &e;
	p = "hello"
	// &p p
	p = (int *)malloc(4);

	printf("&p = %p\n", &p);
	printf("&a = %p\n", &a);
	printf("&b = %p\n", &b);
	printf("p = %p\n", p);
	printf("&e = %p\n", &e);
	printf("&ee = %p\n", &ee);
	printf("hello = %p\n", "hello");//const
	return 0;
}
