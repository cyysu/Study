
#include <stdio.h>

int main(void)
{
	int sum = 0 ; 

	
	__asm__ __volatile__ (

	"mov	r0 , #33  \n"

	
	"ldr	r1 , =next\n"
	"mov	pc , r1   \n"
	"mov	r0 , #22  \n"
	"next:            \n"

	"mov	%0 , r0   \n"
	:"=r"(sum)
	::"r0","r1"
	);


	printf("sum:%d \n" , sum);

	return 0 ; 
}
