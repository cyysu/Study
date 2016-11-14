#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float test(void)
{
	return 3.45;
}
int main(void)
{
	char ch = 'a';
	char ch = '1';

	int a;
	float f;
	printf("ret test = %d\n", (int)test());

	f = 2.33 + 4.55 + 123;

	printf("f = %f\n", f);

	a = 'a';

	printf("a = %d a = %c\n", a, a);
	printf("ch = %c ch = %d\n", ch, ch);
	return 3.45;
}
