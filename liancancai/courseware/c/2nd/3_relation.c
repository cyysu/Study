#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a = 1, b = 2;
	//成立1 不成立0
	printf("a > b = %d\n", a > b);//0
	printf("a >= b = %d\n", a >= b);//0
	printf("a < b = %d\n", a < b);//1
	printf("a <= b = %d\n", a <= b);//1
	printf("a != b = %d\n", a != b);//1
	printf("a == b = %d\n", a == b);//0

	return 0;
}
