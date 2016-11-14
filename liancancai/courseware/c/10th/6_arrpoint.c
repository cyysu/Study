#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int (*p)[2] = NULL;//数组指针

	printf("sizeof(p) = %d\n", sizeof(p));
	printf("sizeof(p[0]) = %d\n", sizeof(p[0]));
	printf("sizeof(p[1]) = %d\n", sizeof(p[1]));
	printf("sizeof(p[2]) = %d\n", sizeof(p[2]));


	p = (int (*)[2])malloc(sizeof(p[0]) * 5);
	/*p = (int **)malloc(sizeof(p[0]) * 5);*/

	printf("p = %p\n", p);

	return 0;
}
