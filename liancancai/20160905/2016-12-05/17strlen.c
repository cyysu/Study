
#include <stdio.h>

int main(void)
{
	char *p = "hello world" ; 

	int sum = 0 ;

	__asm__ __volatile__ (

	"mov	r0 , %1   \n"  //地址
	"mov	r1 , #0   \n"  //算个数

	"loop:	          \n"

	"ldrb	r2 , [r0] \n"
	"cmp	r2 , #0   \n"
	"addne	r1 , #1   \n"
	"addne	r0 , #1   \n"
	"bne	loop      \n"
	"mov	%0 , r1   \n"

	:"=r"(sum)
	:"r"(p)
	:"r0","r1","r2"
	);

	printf("sum:%d \n" , sum);
	
	return 0 ; 
}
