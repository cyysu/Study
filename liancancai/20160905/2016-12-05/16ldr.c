
#include <stdio.h>

int main(void)
{
	int a = 100 ;


	__asm__ __volatile__ (

	"mov	r0 , %0   \n"
	"ldr	r1 , [r0] \n" //将r0的值当作地址,将该地址的值取出给r1
	"add	r1 , #100 \n"
	"str	r1 , [r0] \n" //将r1的值写入r0的值作为地址中   *r0=r1 ;

	::"r"(&a)
	:"r0","r1"
	);

	printf("a:%d \n" , a);

	return 0 ;
}
