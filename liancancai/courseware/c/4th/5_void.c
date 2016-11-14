#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int e;//全局变量

void test(void);
int add(int, int);

/*int mul(int a, int b)*/
//老式程序员函数格式
int mul(a, b)
int a;
int b;
{
	return a * b;
}
void check(void)
{
	printf("e = %d\n", e);
	printf("a = %d\n", a);
}

int main(void)
{
	test();	
	check();
	int a = 2, b = 3;
	printf("add = %d\n", add(a, b));
	printf("mul = %d\n", mul(a, b));
	/*printf("mul = %f\n", mul(2.3, 3));*/

	/*test(123);*/
    /*
	 *test(123, 456);
	 *test(123, 'A', 3.456);
	 *test(123, "lkshdlja");
     */
	return 0;
}
void test(void)
{
	printf("test!\n");
}

int add(int c, int d)
{
	return c + d;
}
