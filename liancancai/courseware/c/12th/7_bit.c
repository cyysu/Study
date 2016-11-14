#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct a_t{
	unsigned int a : 33;//4 -> 32
/*
 *    int b:2;
 *    int c:2;
 *    int d:2;
 *    int f:2;
 *    int g:2;
 *    int h:2;
 *
 */
	char ch;
};


int main(void)
{
	struct a_t a;

	a.a = 4;
	printf("a.a = %d\n", a.a);
	printf("sizeof(a) = %d\n", sizeof(a));
	return 0;
}
