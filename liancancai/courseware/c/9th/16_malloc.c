#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test(int **p)
{
	
}
int main(void)
{
	int *p = NULL;


	free(p);
	free(p);
	free(p);
	free(p);
	free(p);
	free(p);

	int **q = NULL;

	// &q q *q **q
	printf("&q = %p\n", &q);
	q = (int **)malloc(sizeof(int *));
	if (q == NULL)
	{
		return -1;
	}
	printf("q = %p\n", q);
	*q = (int *)malloc(sizeof(int));
	if (*q == NULL)
	{
		free(q);
		return -1;
	}
	printf("*q = %p\n", *q);

	**q = 123;

	printf("**q = %d\n", **q);
	free(*q);
	free(q);
	free(q);
/*
 *    test(&p);
 *
 *    *p = 123;
 *
 *    printf("*p = %p\n", *p);
 */
	return 0;
}
