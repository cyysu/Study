#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	while (0)
	{
		printf("hello!\n");
	}


	do
	{
		printf("do while!\n");
	}while(0);

	int i;

	i = 1;
	do
	{
		printf("%d ", i);
		i++;
	}while(i < 10);
	printf("\n");

	int j;

	i = 0;
	do{
		j= 0;
		do{
			printf("+");
			j++;
		}while(j < 10);
		printf("\n");
		i++;
	}while(i < 10);
	return 0;
}
