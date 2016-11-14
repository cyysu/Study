#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int (FUNC)(int, int);


int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a * b;
}
int div_(int a, int b)
{
	return a / b;
}

void test(int a, int b, FUNC *func)
{
	printf("test = %d\n", func(a, b));
}
int main(void)
{
	int i;
	int a = 5, b = 2;
	int (*func)(int, int);//定义一个函数指针

	int (*p[4])(int, int) = {add, sub, mul, div_};//函数指针数组

	for (i = 0; i < 4; i++)
	{
		test(a, b, p[i]);
	}
    /*
	 *test(a, b, add);
	 *test(a, b, sub);
	 *test(a, b, mul);
	 *test(a, b, div_);
     */

	func = add;
	func = sub;
	func = mul;
	printf("ret = %d\n", func(a, b));

	printf("add = %d\n", add(a, b));
	printf("sub = %d\n", sub(a, b));
	printf("mul = %d\n", mul(a, b));
	printf("div = %d\n", div_(a, b));
	return 0;
}
