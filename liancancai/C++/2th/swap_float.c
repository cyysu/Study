#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	double a = 1.11;
	double b = -2.22;

	a ^= b;
	b ^= a;
	a ^= b;

	printf("a = %lf, b = %lf", a, b);

	return 0;
}
