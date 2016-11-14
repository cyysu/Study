#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char s[] = "hello";

	printf("sizeof(s) = %d\n", sizeof(s));//6 10 5 7 
	printf("s = %s\n", s);
	putchar('=');
	putchar('\0');
	printf("NULL");
	putchar('=');
	return 0;
}
