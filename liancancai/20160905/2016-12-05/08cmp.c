
#include <stdio.h>


int main(void)
{
	int sum = 0 ; 
	
	__asm__ __volatile__ (

	"mov	r0 , #1    \n"
	"mov	r1 , #1    \n"
	
	"cmp	r0 , r1    \n"

	//<c><q>
	//ne  eq  gt  ge  lt  le
	//!=  ==  >   >=  <   <=
	
	"movne	%0 , #11   \n"
	"moveq  %0 , #22   \n"


	:"=r"(sum)
	::"r0","r1"
	);

	printf("sum:%d \n" , sum);

	return 0 ; 
}
