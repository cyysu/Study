#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int a = 1, b = -2;

	a ^= b;
	b ^= a;
	a ^= b;

	printf("a = %d, b = %d\n", a, b);
	return 0;
}
