#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i, j;
	int sum = 0;

	i = 1;
	while (i < 100)
	{
		sum += i;
		/*printf("%d ", i);*/
		i += 2;
	}
	printf("1 + 3 + 5 + ... + 99 = %d\n", sum);

	sum = 0;
	i = 2;
	do{
		sum += i;
		i += 2;
	}while(i <= 100);
	printf("2 + 4 + 6 + ... + 100 = %d\n", sum);

    /*
	 *i = 1;
	 *while (i < 10)
	 *{
	 *    j = 1;
	 *    while(j <= i)
	 *    {
	 *        printf("%d * %d = %2d  ", j, i, i * j);
	 *        j++;
	 *    }
	 *    printf("\n");
	 *    i++;
	 *}
     */
	printf("============\n");
	i = 1;
	do{
		j = 1;
		do{
			printf("%d X %d = %-2d  ", j, i, i * j);
			j++;
		}while(j <= i);
		printf("\n");
		i++;
	}while(i < 10);

	return 0;
}
