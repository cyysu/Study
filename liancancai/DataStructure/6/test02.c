#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int globe = 1;

int fun1(void)
{
	return (globe += 10);
}


int fun2(void)
{
	return (globe += 100);
}

int main(void)
{
	globe = 1;
	printf("fun1 = %d fun2 = %d\n", fun1(), fun2());
	
	globe = 1;
	printf("fun2 = %d fun1 = %d\n", fun2(), fun1());
	return 0;
}
