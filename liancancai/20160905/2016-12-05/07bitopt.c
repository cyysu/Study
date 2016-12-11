
#include <stdio.h>

int main(void)
{

	int sum  = 0 ; 

	__asm__ __volatile__ (

	//  &  |  ~

	"ldr	r0 , =0x1   \n"
	"ldr	r1 , =0x0   \n"

	//AND{S}{<c>}{<q>}    {<Rd>,} <Rn>, <Rm> {, <shift>}
	//&
	"orr	r1 , r0 ,lsl #4  \n" //  r1 = r1 & r0 ; 
	
	// |
	//"orr	r2 , r0 , r1   \n"
	
	// ~
	//"mvn	r0 , #0    \n"

	"mov	%0 , r1     \n"

	:"=r"(sum)
	::"r0","r1","r2"
	);

	printf("sum:%d \n" , sum);

	return 0 ; 
}
