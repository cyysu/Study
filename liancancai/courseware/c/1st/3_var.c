#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//定义变量
	//常量：值不可以改变 1 "hello"
	char ch = 'a';
	int a = 123;

	printf("sizeof(ch) = %d\n", sizeof(ch));//1
	printf("sizeof(char) = %d\n", sizeof(char));//1
	printf("sizeof(a) = %d\n", sizeof(a));//4
	printf("sizeof(int) = %d\n", sizeof(int));

	printf("a = %d\n", a);
	a = 456;

	printf("ch = %c\n", ch);
	printf("a = %d\n", a);

	return 0;
}
