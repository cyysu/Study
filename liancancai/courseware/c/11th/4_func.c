#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRI printf

#define TEST(...) printf(__VA_ARGS__)
#define PRI_I(a) printf(#a" = %d\n", a)
#define PRI_F(a) printf(#a" = %f\n", a)

#define TEST1(a, b) a##b

int main(void)
{
	int a = 1, b = 3, hello = 456;

	int TEST1(a, b) = 123;

	printf("ab = %d\n", ab);


	printf("hello!\n");
	PRI("world!\n");
	TEST("hello!\n");
	TEST("a = %d b = %d\n", a, b);
	PRI_I(a);
	PRI_I(b);
	PRI_I(hello);

	
	return 0;
}
