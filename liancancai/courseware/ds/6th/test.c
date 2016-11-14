#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test(int *p)
{
	
}
int main(void)
{
	int *p = NULL;

	*p = 1023;

	test(p);

	printf("*p = %d\n", *p);
	return 0;
}
