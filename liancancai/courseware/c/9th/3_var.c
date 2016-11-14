#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a = 40;

void test(void)
{
	printf("test : a = %d\n", a);
	int a = 20;//局部变量，只有test函数可以访问

	printf("test : a = %d\n", a);
}

void test1(int a)
{
	/*int a = 200;*/

	int *p = NULL;

	p = (int *)malloc(4);

	*p = 123;

	printf("*p = %d\n", *p);
	free(p);

	*p = 456;
	/*free(p);*/
	printf("*p = %d\n", *p);

	printf("test1 : a = %d\n", a);
}
int main(void)
{
	int a = 10;//局部变量
	/*int a = 20;//在作用域相同的条件下。不能重复定义相同的变量名*/

	test1(a);
	printf("==============\n");

	{
		int a = 30;//模块变量
		printf("mode : a = %d\n", a);
	}
	test();

	printf("main : a = %d\n", a);
	return 0;
}
