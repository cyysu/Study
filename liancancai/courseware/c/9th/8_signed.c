#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	unsigned short s = 32767 + 1;//2 -> 16 符号位 15
	//-32768 ~ 32767 signed
	// 0 ~ 65535 unsigned;

	register int b = 123;

	s = -1;

	printf("s = %d\n", s);
	return 0;
}
