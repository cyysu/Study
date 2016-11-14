#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int add(int a, int b)
{
	return a + b;
}

int mul(int a, int b)
{
	return a * b;
}

int add_mul(int a,int b, int flag)
{
	if (flag == 1)
		return a + b;
	else if (flag == 2)
		return a - b;
	else if (flag == 3)
		return a / b;
	else if (flag == 4)
		return a * b;
	return 0;
}
int main(void)
{
	int flag;
	printf("please flag(1 -> add 2 -> sub 3 -> dev 4-> mul) : ");
	scanf("%d", &flag);

	printf("add_mul = %d\n", add_mul(2, 3, flag));

	return 0;
}
