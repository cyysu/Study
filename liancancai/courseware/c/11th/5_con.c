#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 *#define a 1
 *
 *#undef a
 *
 */
int main(void)
{
	/*int a = 1;*/
#if a
	printf("hello!\n");
#elif B
	printf("hhhh!\n");
#elif C
	printf("world!\n");
#else
	printf("tttt!\n");
#endif
	return 0;
}
