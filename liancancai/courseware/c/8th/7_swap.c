#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a = 1, b = 2, tmp;
	int *p = &a, *q = &b;

	printf("before : a = %d b = %d\n", a, b);
	tmp = *p;
	*p = *q;
	*q = tmp;
	printf("after : a = %d b = %d\n", a, b);

	return 0;
}
