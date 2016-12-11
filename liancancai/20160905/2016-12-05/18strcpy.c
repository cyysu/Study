
#include <stdio.h>

int main(void)
{
	char *p = "hello kitty" ;
	char Buffer[20];


	__asm__ __volatile__ (








	::"r"(p),"r"(Buffer)
	:
	);

	printf("Buffer:%s \n" , Buffer);
	
	return 0 ; 
}

