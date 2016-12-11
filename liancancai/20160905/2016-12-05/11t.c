
#include <stdio.h>

int main(void)
{
	int sum  = 0 ; 

	__asm__ __volatile__ (

	//@

	"mov	r0 , #0   \n"
	"mov	r1 , #1   \n"

	"loop:			  \n"

	"add	r0 , r1   \n"

	"cmp	r1 , #100 \n"
	"add	r1 , r1 , #1   \n"
	"bne	loop          \n"

	"mov	%0 , r0   \n"

	:"=r"(sum)
	::"r0","r1"
	);
	
	printf("sum:%d \n" , sum);

	return 0 ; 
}
