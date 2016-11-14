#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int step(int num)
{
	if (num == 1)
		return 1;
	if (num == 2)
		return 2;
	if (num == 3)
		return 4;
	return step(num - 1) + step(num - 2) + step(num - 3);
}
int main(void)
{
	printf("count = %d\n", step(9));

	return 0;
}
