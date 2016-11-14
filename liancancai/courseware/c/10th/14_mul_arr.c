#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int **test(int a, int b)
{
	int **p = NULL;

	return p;
}
int main(void)
{
	int i, j;
	int **p = NULL;

	p = test(2, 3);

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			p[i][j] = rand() % 100;
		}
	}
	return 0;
}
