#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PI 
//全局变量
int e;


int main(void)
{
	//局部变量
	//定义两个变量
	int a = 12, b = 7;
	/*int a;*/
	int c;
	int e = 10;
	float f = 2.33;

	f--;

	printf("f = %f\n", f);
	printf("f = %f\n", f / 10);

	{
	//模块变量
		int e = 20;
	}

	//先赋值，再自加 => 后缀自加
	/*c = a++;*/
	//先自加，再赋值 => 前缀自加
	/*c = ++a;*/
	c = ++b+(++a);// => b++ + a | b + ++a

	a = 2;

	printf("%d : %d : %d", a++, ++a, a++);


	printf("a = %d b = %d c = %d\n", a, b, c);//13 12 | 13 13 | 12 13 | 12 12

	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);//84
	printf("%d / %d = %d\n", a, b, a / b);//1
	printf("%d %% %d = %d\n", a, b, a % b);//5
	c = a + b;
	printf("add = %d\n", c);
	//打印两个变量
	printf("a = %d b = %d\n", a, b);
	
	printf("c = %d\n", c);
	printf("e = %d\n", e);
	return 0;
}
