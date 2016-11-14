#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i;//循环变量
	int j;

	char ch = 'A';

	putchar('A');
	putchar(ch);
	putchar(10);


	for (i = 1; i < 10; i++)
	{
		printf("%d ", i);
	}
	putchar(10);

	for (i = 9; i > 0; i--)
	{
		printf("%d ", i);
	}
	putchar(10);


	for (i = 0; i < 4; i++)
	{
		printf("####****\n");
		for (j = 0;j < 8; j++)
		{
			if (j < 4)
			{
				printf("#");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}
