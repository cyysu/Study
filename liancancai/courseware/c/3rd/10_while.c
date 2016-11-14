#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int j;

	printf("i = %d\n", i);

	i = 1;//init
	while(i < 10)//con
	{
		printf("%d ", i);//body
		i++;//add
	}
	printf("\n");


	printf("==============\n");
	i = 0;
	while(i < 10)
	{
        /*
		 *for (j = 0; j <= i; j++)
		 *{
		 *    printf("* ");
		 *}
         */
		j = 0;
		while (j <= i)
		{
			printf("* ");
			j++;
		}
		printf("\n");
		i++;
	}
	printf("==============\n");
	return 0;
}
