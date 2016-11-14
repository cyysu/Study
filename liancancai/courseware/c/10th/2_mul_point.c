#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//多极指针和函数关系
int **test(void)//返回值
{
	int **p = NULL;

	p = (int **)malloc(sizeof(int *));
	if (p == NULL)
	{
		printf("malloc p\n");
		return NULL;
	}

	*p = (int *)malloc(sizeof(int));
	if (*p == NULL)
	{
		printf("malloc *p!\n");
		free(p);
		return NULL;
	}

	printf("test : p = %p *p = %p\n", p, *p);
	return p;
}

void test1(int ***p)//形参
{
	// p *p **p

	printf("&p = %p\n", &p);
	printf("p = %p\n", p);
	*p = (int **)malloc(sizeof(int *));
	if (NULL == *p)
	{
		printf("malloc *p failed!\n");
		return ;
	}
	printf("*p = %p\n", *p);
	**p = (int *)malloc(sizeof(int));
	if (**p == NULL)
	{
		printf("malloc **p failed!\n");
		free(*p);
		return ;
	}
	printf("**p = %p\n", **p);
	// &p p *p **p ***p
}
int main(void)
{
	int **p = NULL;
	// &p p *p **p

	//申请两次 p int ** sizeof(int *) 
	// *p   int * sizeof(int)
	//main

	#if 0
	p = test();
	#else
	//必须传变量地址
	test1(&p);
	#endif
	printf("main : p = %p *p = %p\n", p, *p);
	**p = 123;

	printf("**p = %d\n", **p);

	free(*p);
	free(p);
	return 0;
}
