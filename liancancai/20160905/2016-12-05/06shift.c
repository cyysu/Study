
#include <stdio.h>

int main(void)
{
#if 0
	int a = -6 ; 
	unsigned int b = 3 ; 
	int c ; 
	c = a + b ; 

	printf("c:%s  sum:%s \n" ,(c>0)?"YES":"NO",((a+b)>0)?"YES":"NO");
#endif

#if 0
	//算术  逻辑
	//右移  如果无符号补0   如果有符号,补符号位
	int num = 0xFFFFFFFF ; 
	
	printf("num:%p \n" , num >> 20);
#endif

#if 1
	int sum = 0 ; 

	__asm__ __volatile__ (

	//"mov	r0 , #0xF   \n"
	//"lsl	r0 , #4     \n"  //左移只有逻辑左移
	"ldr	r0 , =0x70000000  \n"
	//逻辑右移
	//"lsr	r0 , #4           \n"
	//算术右移
	"asr	r0 , #4           \n"

	"mov	%0 , r0     \n"
	:"=r"(sum)
	::"r0"
	);
	printf("sum:%#010x \n" , sum);
#endif

	return 0 ; 
}
