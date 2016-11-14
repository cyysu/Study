#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//int main(void)
int main(int argc, char *argv[])
{
	int i, j;

	printf("argc = %d\n", argc);
	for (i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	for (j = 0; j < 10; j++)
	{
		printf("argv[1][%d] = %c\n", j, argv[1][j]);
	}

	printf("==> %d\n", 123);
	printf("===> %s\n", "123");
	return 0;
}
