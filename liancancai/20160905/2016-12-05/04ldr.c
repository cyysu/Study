
#include <stdio.h>

int main(void)
{

	int sum = 0 ; 

	__asm__ __volatile__ (
	//将一个立即数给一个寄存器
	
	"ldr	r0 , =0xFFFFFFFF \n"
	"mov	%0 , r0    \n"

	:"=r"(sum)
	::"r0"
	);
	
	printf("sum:%p \n" , sum);

	return 0 ; 
}
