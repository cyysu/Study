
//#include <stdio.h>

int main(void)
{
	//返回值是寄存器r0
#if 0
	__asm__ __volatile__ (

	"mov	r0 , #33  \n"
	"mov	pc , lr   \n"  //return  r0 ; 

	);

	printf("hello kitty \n");
#endif

	return 0; 
}
