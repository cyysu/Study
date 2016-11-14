#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*int main(void)*/
int main(int a, char *b[])
{
	int i;
	for (i = 0; i < a; i++)
	{
		printf("b[%d] = %s\n", i, b[i]);
	}
	return 0;
}
