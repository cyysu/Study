#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cls_t{
	int a;
	int b;
};

union a_t{
	int a;
	int b;
};
int main(void)
{
	struct cls_t a;
	union a_t at;

	at.a = 123;
	at.b = 456;

	printf("sizeof(at) = %d\n", sizeof(at));
	printf("at.a = %d\n", at.a);
	printf("at.b = %d\n", at.b);

	printf("&at = %p\n", &at);
	printf("&at.a = %p\n", &at.a);
	printf("&at.b = %p\n", &at.b);

	printf("&a = %p\n", &a);
	printf("&a + 1 = %p\n", &a + 1);
	printf("&a.a = %p\n", &a.a);
	printf("&a.a + 1 = %p\n", &a.a + 1);
	printf("&a.b = %p\n", &a.b);
	return 0;
}
