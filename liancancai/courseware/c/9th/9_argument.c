#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test(int *a)
{
	printf("test : *a = %d\n", *a);
	*a = 456;
	printf("test : *a = %d\n", *a);
}

void test1(void *a)
{
	printf("*a = %d\n", *(int *)a);
	*(int *)a = 123456;
}
void swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}
int main(void)
{
	int a = 123;
	int b = 456;

	printf("a = %d b = %d\n", a, b);
	swap(&a, &b);
	printf("a = %d b = %d\n", a, b);
	test(&a);
	test1(&a);
	printf("main : a = %d\n", a);

	return 0;
}
