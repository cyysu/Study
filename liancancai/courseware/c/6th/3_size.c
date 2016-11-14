#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5

int main(void)
{
	int a[MAX];

	printf("sizeof(a) = %d\n", sizeof(a));//40
	printf("sizeof(a[0] = %d\n)", sizeof(a[0]));//4
	printf("len = %d\n", sizeof(a) / sizeof(int));
	return 0;
}
