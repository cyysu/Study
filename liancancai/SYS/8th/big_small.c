#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union big_small{
	int a;
	char b;
};

int main(int argc, char **argv)
{
	// int a = 1;
	// printf("char(a) = %d\n", (char) a);
	union big_small big;
	big.a = 1;

	if (big.b)
	{
		printf("小端模式\n");
	}
	else
	{
		printf("大端模式\n");
	}

	return 0;
}
