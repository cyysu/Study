#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int *p;
	char *ch;

	printf("sizeof(p) = %d\n", sizeof(p));
	printf("sizeof(int *) = %d\n", sizeof(int *));
	printf("sizeof(ch) = %d\n", sizeof(ch));
	printf("sizeof(char *) = %d\n", sizeof(char *));
	printf("sizeof(short *) = %d\n", sizeof(short *));
	printf("sizeof(int *) = %d\n", sizeof(int *));
	printf("sizeof(long *) = %d\n", sizeof(long *));
	printf("sizeof(float *) = %d\n", sizeof(float *));
	printf("sizeof(double *) = %d\n", sizeof(double *));
	printf("sizeof(long double *) = %d\n", sizeof(long double *));
	return 0;
}
