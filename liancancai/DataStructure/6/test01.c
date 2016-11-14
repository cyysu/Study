#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pow2(int a)
{
	a --;
	a |= a >> 1;
	a |= a >> 2;
	a |= a >> 4;
	a |= a >> 8;
	a |= a >> 16;

	return a + 1;
}

int main(void)
{
	int num;
	printf("please input a num:");
	scanf("%d", &num);

	printf("pow2 = %d\n", pow2(num));
	return 0;
}
