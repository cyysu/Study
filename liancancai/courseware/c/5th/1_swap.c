#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void hello(void);

void swap(int a, int b)
{
	int	tmp;
	printf("swap a = %d, b = %d\n", a, b);
	tmp = a;
	a = b;
	b = tmp;
	printf("swap a = %d, b = %d\n", a, b);

	void hello(void)
	{
		printf("hello1\n");
	}

	hello();
}
int main(void)
{
	int a = 2, b = 3;
	int tmp;

	hello();
	printf("before : a = %d b = %d\n", a, b);
	swap(a, b);
	printf("after  : a = %d b = %d\n", a, b);

	return 0;
}
