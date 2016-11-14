#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//求1000以内水仙化数
//num = 123456
//num / 100000 % 10	=> 1
//num / 10000 % 10 	=> 2
//num / 1000 % 10 	=> 3
//num / 100 % 10	=> 4
//num / 10 % 10		=> 5
//num / 1 % 10		=> 6
int main(void)
{
	int i, bit, sum = 0, tmp;
	
	i = 1;
	while(i < 1000)
	{
		tmp = i;
		while(tmp)
		{
			bit = tmp % 10;
			sum += bit * bit * bit;
			tmp = tmp / 10;
		}

        /*
		 *printf("i = %d sum = %d\n", i, sum);
		 *getchar();
         */
		if (sum == i)
		{
			printf("%d ", i);
		}

		sum = 0;
		i++;
	}
	printf("\n");
	
	return 0;
}
