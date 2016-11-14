#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int add(int low, int high)
{
	int i, sum;

	for (i = low; i <= high; i++)
	{
		sum += i;
	}

	return sum;
}

int main(void)
{
	int result[10];

	result[0] = add(1, 10);
	result[1] = add(1, 100);

	printf("result[0] = %d, result[1] = %d\n", result[0], result[1]);
	return 0;
}
