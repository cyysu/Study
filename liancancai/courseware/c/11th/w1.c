#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//用二级指针模拟二维数组
int **test(int a, int b)
{
	int i, j;
	int **p = NULL;

	//保存行首地址
	p = (int **)malloc(sizeof(int *) * a);
	if (NULL == p)
	{
		return NULL;
	}
	for (i = 0; i < a; i++)
	{
		*(p + i) = (int *)malloc(sizeof(int) * b);
		if (NULL == *(p + i))
		{
			for (j = 0; j < i; j++)
			{
				free(p[j]);
			}
			free(p);
			return NULL;
		}
	}
	return p;
}
int main(void)
// 'r' "r"
/*
 *int main(int argc, char *argv[])
 *int main(int argc, char **argv)
 */
{
	int i, j;
	int **p = NULL;
	int a, b;

	printf("please input a and b : ");
	scanf("%d%d", &a, &b);

    /*
	 *i = 5;
	 *while(--i)
	 *{
	 *    printf("%d ", i);
	 *}
	 *printf("\n");
     */
	p = test(a, b);

	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			p[i][j] = rand() % 100;
		}
	}
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			printf("%d : %p | ", p[i][j], &p[i][j]);
		}
		printf("\n");
	}

	printf("p = %p p + 1 = %p\n", p, p + 1);
	printf("*p = %p *p + 1 = %p\n", *p, *(p + 1));
	return 0;
}
