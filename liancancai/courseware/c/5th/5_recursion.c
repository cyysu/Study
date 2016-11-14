#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void A(void)
{
	int count = 0;
	if (count == 5)
	{
		return ;
	}
	count++;
	printf("AAAAAAAAAA! &count = %p\n", &count);
	A();
}

int main(void)
{
	A();
    /*
	 *while(1)
	 *{
	 *    printf("AAAAAAAAAAA!\n");
	 *}
     */
	return 0;
}
