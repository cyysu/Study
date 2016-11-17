#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test(void)
{
	static int a = 1;
	a += 1;
	printf("%d\n", a);
}

int main(int argc, char **argv)
{
	test();
	test();
	test();
	return 0;
}
