#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union a_t{
	int a;
	char ch;
};

int main(void)
{
	int i;
	union a_t a;

	int b = 0x11223344;

	for (i = 0; i < 4; i++)
	{
		printf("%p : %#x\n", (char *)&b + i, *((char *)&b + i));
	}
	a.a = 1;

	if (a.ch == 1)
	{
		printf("little!\n");
	}
	else
	{
		printf("big!\n");
	}
	printf("&a.a = %p\n", &a.a);
	printf("&a.a = %p\n", (char *)&a.a + 1);
	printf("&a.a = %p\n", (char *)&a.a + 2);
	printf("&a.a = %p\n", (char *)&a.a + 3);
	printf("&a.a + 1 = %p\n", &a.a + 1);
	return 0;
}
