#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void B(void);

void A(void)
{
	printf("AAA!\n");
	B();
}

void B(void)
{
	printf("BBB!\n");
	A();
}
int main(void)
{
	A();
	return 0;
}
