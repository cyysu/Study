
#include <stdio.h>

int (*ppp)(const char *fmt , ...) = (void *)0x4003c0 ; 

int main(void)
{
	ppp("hello kitty \n");

	printf("hello world %p\n" , printf);

	return 0 ; 
}

