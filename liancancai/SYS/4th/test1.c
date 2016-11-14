#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//求素数
int main(int argc, char **argv)
{
	int i;
	int j;
	int count = 0;
	int start_num, end_num;

	printf("printf intput start num and end num:");
	scanf("%d %d", &start_num, &end_num);


	for (i = start_num; i <= end_num; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (i % j == 0 && j != i && j != 1)
			{
				break;
			}

			if (j == i)
			{
				printf("%d\n", i);
				count ++;
			}
		}
	}
	// printf("7 / 2 = %d\n", 7 / 2);
	printf("count = %d\n", count);	
	return 0;
}
