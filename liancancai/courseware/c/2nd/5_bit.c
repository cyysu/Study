#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test(int num)
{
	int i;

	for (i = 31; i >= 0; i--)
	{
		if ((i + 1) % 4 == 0)
			putchar(' ');
		printf("%d", (num >> i) & 1);
	}
	printf("\n");
}
int main(void)
{
	int a = 1234, b = 456789;
	int c = -123456;

	a = -123455;
	test(a);
	test(a << 15);
	printf("a = %d\n", a << 15);
	printf("a = %d\n", a << 1);

	printf("==================\n");
	
    /*
	 *test(c);
	 *test(~c);
	 *printf("===========\n");
     */
	test(a);
	test(b);
	test(a ^ b);

	printf("~c = %d\n", ~c);

	printf("~a = %d\n", ~a);

	printf("value123 = %#o\n", 123);
	printf("value123 = %#x\n", 123);
	printf("a & b = %d\n", a & b);//2 0
	printf("a | b = %d\n", a | b);//2 0
	return 0;
}
