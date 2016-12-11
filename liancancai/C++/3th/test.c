#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char c;
	int i;
	for (c = 0, i = 0; i < atoi(argv[1]); i++, c ++)
	{
		printf("%d ", c);
	}
	putchar(10);
	return 0;
}
