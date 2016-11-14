#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void hello(void)
{
	printf("hello!\n");
}
void world(void)
{
	printf("world!\n");
}

int add(int a, int b)
{
	printf("add!\n");
	return a + b;
}

//函数指针
int main(void)
{
	void *p = NULL;

	void (*func)(void);//函数声明 -> 函数指针
	int (*FUNC)(int, int);

	func = hello;

	func = world;

	FUNC = add;

	FUNC(12, 34);
	/*p = hello;*/

/*
 *    printf("p = %p\n", p);
 *    printf("hello = %p\n", hello);
 *
 *    hello();
 */


	return 0;
}
