#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i, j;
	int sum = 0;

	for (i = 1; i <= 100; i++)
	{
		sum += i;
	}
	printf("1 + 2 + 3 + ... + 100 = %d\n", sum);

	for (i = 1; i < 10; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d * %d = %2d  ", j, i, i * j);
		}
		printf("\n");
	}
	return 0;
}
