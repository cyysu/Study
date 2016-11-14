#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a[3][5] = {1,2};
	int b[2][3][3] = {{{}, {2, 3, 4}, {}}, 
					  {{}, {8}, {5, 6}}};
	
	printf("110 = %d\n", b[1][1][0]);
	// &b			: +1 => 18 * 4
	// b			: +1 => 3 * 3 * 4
	// b[0]			: +1 => 3 * 4
	// b[0][0]		: +1 => 4
	// &b[0][0][0]	:


	int i, j;

	//	&a 	: 24	表示整个数组首地址 +1偏移整个数组大小
	// 	a	: 12	表示数组行首地址 +1偏移一行大小
	//	a[0]: 4		表示数据列首地址 +1偏移一列大小 一个数据元素大小

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5;  j++)
		{
			a[i][j] = rand() % 100;
		}
	}
	printf("&a = %p &a + 1 = %p\n", &a, &a + 1);
	printf("a = %p a + 1 = %p\n", a, a + 1);
	printf("a[0] = %p a[0] + 1 = %p\n", a[0], a[0] + 1);
	printf("&a[0][0] = %p\n", &a[0][0]);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5;  j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("==============\n");
	for (i = 0; i < 15; i++)
	{
		printf("%d ", a[0][i]);
	}
	printf("\n");
	return 0;
}
