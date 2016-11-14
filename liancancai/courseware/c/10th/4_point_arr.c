#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//多维数组等价数组指针
int main(void)
{
	int i, j;
	int a[2][3] = {1,2,3,4,5,6};
	int (*p)[3] = NULL;//数组指针
	int *q;

		
	/*q = a[0];*/

	printf("sizeof(p) = %d\n", sizeof(p));
	printf("sizeof(p[0]) = %d\n", sizeof(p[0]));
	p = a;

	printf("== %d\n", **p);

	printf("&p = %p &p + 1 = %p\n", &p, &p + 1);
	printf("a = %p a + 1 = %p\n", a, a + 1);
	printf("p = %p p + 1 = %p\n", p, p + 1);

	p[1][1] = 1122;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			/*printf("%d ", a[i][j]);*/
			printf("%d ", (*(p + i))[j]);
		}
	}
	printf("\n");
	return 0;
}
