#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int * INT;
/*#define INT int **/

int main(void)
{
	int a;
	INT b;

	INT p, q;

	p = &a;
	q = &a;

	/*b = 123;*/

	printf("b = %d\n", b);
	return 0;
}
