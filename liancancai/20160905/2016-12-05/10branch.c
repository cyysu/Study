
#include <stdio.h>

int main(void)
{

	int sum = 0 ; 

	__asm__ __volatile__ (

	"mov	r0 , #11   \n"

	"b	next		   \n"
	//"b	1f    \n"  //branch  //在以下定义
	//"b	1b    \n"  //branch      //在以上定义
	"mov	r0 , #22   \n"
	"next:             \n"
	//"1:                \n"

	"mov	%0 , r0    \n"

	:"=r"(sum)
	::"r0"
	);

	printf("sum:%d \n" , sum);

	return 0 ; 
}
