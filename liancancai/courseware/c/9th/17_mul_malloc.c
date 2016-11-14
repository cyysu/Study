#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test(int **p)
{
	printf("&p = %p\n", &p);
	printf("p = %p\n", p);
	printf("*p = %p\n", *p);
	*p = (int *)malloc(sizeof(int));

}

int main(void)
{
	int *p = NULL;

	test(&p);
	*p = 123;

	printf("*p = %d\n", *p);


	free(p);
	return 0;
}
