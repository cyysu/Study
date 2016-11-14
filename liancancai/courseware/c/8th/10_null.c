#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int *p = NULL;

	/*p = (int *)20;*/

	/*p = (int *)malloc(sizeof(int));*/
	p = (int *)calloc(1, sizeof(int));
	if (p == NULL)
	{
		printf("malloc failed!\n");
		return -1;
	}
	printf("*p = %d\n", *p);
	printf("=============\n");

	printf("p = %p\n", p);
	/*printf("sizeof(p) = %d\n", sizeof(p));*/
	/*printf("p + 1 = %p\n", p + 1);*/

	*p = 20;

	p  = (int *)realloc(p, sizeof(int) * 2);
	if (p == NULL)
	{
		return -1;
	}
	*(p + 1)= 30;
	/*printf("p = %p\n", p);*/
	printf("p = %p p + 1 = %p\n", p, p + 1);
	printf("*p = %d\n", *p);
	printf("*(p + 1) = %d\n", *(p + 1));

	/*free(p);*/
	free(p);
	/*free(p);*/
	return 0;
}
