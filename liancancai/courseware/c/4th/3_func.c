#include <stdio.h>

//自定义一个函数。实现打印功能

//函数声明
void hello(void);

void world(void)
{
	printf("world!\n");
	hello();//字函数调用子函数
	/*main();*/
}
/*
 *int main(void)
 *{
 *    return -1;
 *}
 */
int main(void)
{

	printf("hello = %p\n",hello);

	/*hello();//函数调用*/
	world();//主函数调用子函数

	/*printf("hello!\n");//库函数 必须包含本函数对应的头文件*/
	//表示调用printf函数，"hello" 表示给库函数传参数
	return 0;
}

//函数实现
void hello(void)
{
	printf("hello!\n");
}
