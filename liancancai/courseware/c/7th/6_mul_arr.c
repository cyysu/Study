#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i, j;

	int a[2][3] = {{1}, {4,5}};//表示二维数组
	/*int a[2][3] = {1,2,3,4};//表示二维数组*/

	

	printf("sizeof(a) = %d\n", sizeof(a));

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("a[%d][%d] = %d %p\n", i, j, a[i][j], &a[i][j]);
		}
		/*printf("\n");*/
	}
	return 0;
}
