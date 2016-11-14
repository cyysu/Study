#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i, j;
	int **p = NULL;
	int a[2][3] = {1,2,3,4,5,6};

	//&a a a[0] => &a[0][0]
	//&a	: 	24
	//a		:	12
	//a[0]	:	4

	//&p	:	4	
	//p		:	4
	//*p	:	4

	p = (int **)malloc(sizeof(int *));
	printf("&p = %p &p + 1 = %p\n", &p, &p + 1);
	printf("p = %p p + 1 = %p\n", p, p + 1);
	printf("*p = %p *p + 1 = %p\n", *p, *p + 1);
	p = a;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			/*printf("a[%d][%d] = %d : %p\n", i, j, a[i][j], &a[i][j]);*/
			/*printf("p[%d][%d] = %d : %p\n", i, j, p[i][j], &p[i][j]);*/
		}
	}
	return 0;
}
