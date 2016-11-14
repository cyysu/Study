#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char **p = NULL;
	char buf1[10] = "1234";
	char buf2[10] = "4567";
	int i = 0;

	p = (char **)malloc(sizeof(char *));
	*p = (char *)malloc(sizeof(char) * 4);
	*(p + 1) = (char *)malloc(sizeof(char) * 4);
	*(p + 2) = (char *)malloc(sizeof(char) * 4);
	*(p + 3) = (char *)malloc(sizeof(char) * 4);

	p[0] = "1234";
	p[1] = "4567";
	p[2] = "1234";
	p[3] = "4567";
	while(p[i] != NULL)
	{
		printf("p[%d] = %s\n", i, p[i]);
		// printf("p[%d] = %p\n", i, p[i]);
		i++;
	}

	return 0;
}
