
#include <stdio.h>

int main(void)
{
	//标准C => 标准库
	//C语言内嵌汇编

	int a = 100 ; 
	int b = 200 ; 
	int c ; 
	//c = a + b ; 

	__asm__ __volatile__ (
	//mov b	add sub mul cmp ldr str bic lsl lsr  asr

	"mov	r0 , %1   \n"  //a
	"mov	r1 , %2   \n"  //b
	"ADd	r2 , r0 , r1   \n"
	"mov	%0 , r2   \n"

	:"=r"(c)	//输出
	:"r"(a),"r"(b)		//输入
	:"r0","r1","r2"			//已经使用过的寄存器
	);

	printf("a:%d b:%d c:%d \n" , a , b , c);
	//r0-r12
	//r13 r14  r15
	//sp  lr   pc
	//cpsr  spsr
	
	return 0 ; 
}
