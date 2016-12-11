
#include <stdio.h>

int main(void)
{

	unsigned int cpsr1 = 0 ; 
	unsigned int cpsr2 = 0 ; 
	
	__asm__ __volatile__ (

	//将cpsr的值读取到r0    mrs =>  move register spsr
	"mrs	r0 , cpsr   \n" //读
	"mov	r1 , #1     \n"
	"mov	r2 , #0     \n"
	"cmp	r1 , r2     \n"
	"mrs	r3 , cpsr   \n"
	//"msr	cpsr , r1   \n"  //mov spsr register

	"mov	%0 , r0     \n"
	"mov	%1 , r3     \n"

	:"=r"(cpsr1),"=r"(cpsr2)
	::"r0","r1","r2","r3"
	);
	printf("cpsr1:%p  cpsr2:%p  \n" , cpsr1 , cpsr2);

	return 0 ; 
}
