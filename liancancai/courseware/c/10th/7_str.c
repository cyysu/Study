#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i = 123;
	int a[5] = {1,2,3,4,5};
	int b[2][3] = {11,22,33,44,55,66};
	int *q = &i;
	char name[10][10] = {"tom", "jim", "mary"};
	char (*s)[10] = NULL;//数组指针

	int *p[10] = {&i, a, q, NULL, b[0]};//指针数组

	printf("sizeof(s) = %d\n", sizeof(s));
	printf("sizeof(p) = %d\n", sizeof(p));

	printf("p[0] = %d\n", *p[0]);
	printf("p[0] = %d\n", *p[2]);
	for (i = 0; i < 5; i++)
	{
		/*printf("%d ", *(p[1] + i));*/
		printf("%d ", p[1][i]);
	}
	printf("\n");
/*
 *    s = name;
 *
 *
 *    for (i = 0; i < 3; i++)
 *    {
 *        printf("%s ", s + i);
 *    }
 *    printf("\n");
 */

	return 0;
}
