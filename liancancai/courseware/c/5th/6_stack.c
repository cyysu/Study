#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void recursion(int num)
{
	if (num == 0)
	{
		return ;
	}
	printf("push = %d\n", num);
	recursion(num - 1);
	printf("pop = %d\n", num);
}

int sum(int num)
{
	if (num == 1)
	{
		return 1;
	}
	return sum(num - 1) + num;
}

int main(void)
{
	
	recursion(5);
	printf("sum = %d\n", sum(100));

	return 0;
}
