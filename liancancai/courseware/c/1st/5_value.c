#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//short => -32768 ~ 32767
//int => -2147483648 ~ 2147483647
int main(void)
{
	short s = 123;//16
	int i = 123;//32

	float f = 5.71;

	s % 10;
	f % 10;

	s = 32767 + 1;
	i = 32767 + 1;
	/*i = 2147483647 + 1;*/

	printf("s = %d\n", s);
	printf("i = %d\n", i);
	return 0;
}
