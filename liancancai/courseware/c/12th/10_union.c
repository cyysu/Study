#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union a_t{
	int a;
	char ch;
	double d;
};

int main(void)
{
	union a_t a;

	a.a = 97;

	printf("a.a = %d\n", a.a);
	printf("a.ch = %c\n", a.ch);
	printf("a.d = %f\n", a.d);
	printf("sizeof(union a_t) = %d\n", sizeof(union a_t));
	return 0;
}
