#include <stdio.h>

void test(char *s)
{
	printf("string!\n");
}

void test(int a)
{
	printf("int!\n");
}


int main(void)
{
	test("hello");
	test(123);
}
