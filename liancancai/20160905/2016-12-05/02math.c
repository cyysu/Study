#include <stdio.h>

int main(void)
{
	int a = 100 ; 
	int b = 20 ; 
	int c ; 

	__asm__ __volatile__ (

	//processor  处理器       coprocessor  协处理器
	"mov	r0 , %1   \n"
	"mov	r1 , %2   \n"
//	"add	r2 , r0 , r1  \n"
//	"sub	r2 , r0 , r1  \n"
	"mul	r2 , r0 , r1  \n"  //mul r0 , r1,lsl #4
	//没有div

	"mov	%0 , r2   \n"

	:"=r"(c)
	:"r"(a),"r"(b)
	:"r0","r1","r2"
	);

	printf("a:%d b:%d c:%d \n" ,a , b ,  c);

	#endif

	return 0 ; 
}
