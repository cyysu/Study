#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//百元百鸡
// 100元 卖 100鸡

int main(void)
{
	int i, j, k;
	int count= 0;

	for (i = 0; i <= 20; i++)
	{
		for (j = 0; j <= 33; j++)
		{
			for (k = 0; k <= 100; k++)
			{
				if (i + j + k == 100 && 5 * i + 3 * j + k / 3 == 100 && k % 3 == 0)
				{
					printf("公鸡：%d 母鸡：%d 小鸡：%d\n", i, j, k);
					count++;
				}
			}
		}
	}
	printf("共 %d 组合！\n", count);
	return 0;
}
