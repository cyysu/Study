
#include <stdio.h>

int main(void)
{

	int sum = 0 ; 

	__asm__ __volatile__ (
	//将一个立即数给一个寄存器
	
	//将一个数据循环右移偶数次之后最低8位可以放得下,如果放不下就出错
	"mov	r0 , #0x01100   \n"  //   #/=
	"mov	%0 , r0    \n"

	:"=r"(sum)
	::"r0"
	);
	
	printf("sum:%d \n" , sum);

	return 0 ; 
}
