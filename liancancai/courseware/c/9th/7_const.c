#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//宏 -> 常量 在预处理的时候替换
#define PI 3.14

int main(void)
{
	/*const int a = 10;*/ //在运行的时候替换
	int a = 10;
	int b = 20;

	// p 地址 *p 值
	/*const int *p = &a;//表示地址可以修改，值不可以修改*/
	/*int * const p = &a;//表示地址不可以修改，值可以修改*/
	const int * const p = &a;//表示地址不可以修改，值不可以修改


	p = &b;
	/**p = 30;*/

    /*
	 *a = 20;
	 *a = b;
     */
	printf("a = %d\n", a);
	return 0;
}
