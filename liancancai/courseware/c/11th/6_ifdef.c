#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define AA 0

/*#undef AA*/

int main(void)
{
	#ifndef AA
	printf("hello!\n");
	#endif
	return 0;
}
