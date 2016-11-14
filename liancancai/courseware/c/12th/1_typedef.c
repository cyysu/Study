#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*#define INT int*/
typedef int *  INT;

int main(void)
{
	INT a, b;

	int *p, *q;
	INT p, q;

	a = 1;
	b = 2;

	printf("a = %d b = %d\n", a, b);
	return 0;
}
