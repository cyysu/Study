#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
h:
	printf("hello!\n");
	goto h;
	
	while(1)
	{
		while(1)
		{
			printf("hello!\n");
			/*break;*/
			/*return -1;*/
			goto loop;
		}
	}
loop:
	printf("main end!\n");
	return 0;
}
