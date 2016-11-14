#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i, j, k;

	int a[2][3][4];
	//a			: 48 
	//a[0]		: 16
	//a[0][0]	: 4
	int (*p)[3][4] = NULL;
	// p

	p = a;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 4; k++)
			{
				p[i][j][k] = rand() % 100;
			}
		}
	}
	printf("p = %p p + 1 = %p\n", p, p + 1);
	printf("p[0] = %p p[0] + 1 = %p\n", p[0], p[0] + 1);
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 4; k++)
			{
				printf("%d ", a[i][j][k]);
			}
		}
	}
	return 0;
}
