
#include "res.h"

int (*printf)(const char *,...) = (void*) 0x43e11ad0 ; 

int _start(void)
{


	//1.configure led register as output
	GPM4CON  &= ~0xFFFF ; 
	GPM4CON  |= 0x1111 ; 


	GPM4DAT &= ~0xF ; 


	printf("hello world \n");


	return 0 ; 
}


