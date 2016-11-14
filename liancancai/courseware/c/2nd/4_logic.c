#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a = 0, b = 1, c = 2;

	printf("c = %d !c = %d !!c = %d\n", c, !c, !!c);// 1 2 ?

	printf("a && b = %d\n", ++a || b++);//1

	printf("a = %d b = %d\n", a, b);// 01 | 12 | 11

	printf("a && b || c = %d\n", a && (b || c));//0
	printf("a || b && c = %d\n", a || b && c);//1
	// 11 | 01 | 10
	return 0;
}
