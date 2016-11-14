#include <stdio.h>

static int e = 12345;


static void hello(void)
{
	printf("hello : e = %d\n", e);
}
void func(void)
{
	hello();
}
