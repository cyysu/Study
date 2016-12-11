
#include <stdio.h>

int main(void)
{
	
	int sum = 0 ; 

	//100%8  ==>  100&0x7
	__asm__ __volatile__ (

	"ldr	r0 , =0xFFFF  \n"
	"mov	r1 , #(0xa<<8)   \n"
	"bic	r2 , r0 , r1  \n"
	"mov	%0 , r2       \n"
	
	:"=r"(sum)
	::"r0","r1","r2"
	);

	printf("sum:%p \n" , sum);


	return 0 ; 
}
