
#include <stdio.h>

int main(void)
{
	int a = 100 ; 
	int b ; 
	//字符串本身有自动粘贴功能
	//printf("hello""world""   haha:%s\n" , (1==0)?"yes":"no");


#if 1

	__asm__ __volatile__ (

	"mov	r0 , %0   \n"
	"mov	%1 , r0   \n"

	
	//%n  从上到下 从左到右 从0开始
	:"=r"(a)                 //输出
	:"r"(b)                  //输入
	:"r0"                  //已经使用过的寄存器
	);
#endif
	printf("b:%d \n" , b);


	return 0 ; 
}
