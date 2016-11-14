#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a = 1000;
	char c = 'A';

	char *ch;
	int *p;
	double *d;

	void *v;

	v = &a;
	printf("v = %d\n", *(int *)v);
	v = &c;
	printf("v = %c\n", *(char *)v);

	printf("void : v = %p v + 1 = %p\n", v, v + 1);
	printf("int : v = %p v + 1 = %p\n", v, (int *)v + 1);
	printf("char : v = %p v + 1 = %p\n", v, (char *)v + 1);
	printf("double : v = %p v + 1 = %p\n", v, (double *)v + 1);
/*
 *    ch = &a;
 *
 *    printf("ch = %d\n", *ch)
 */

	printf("ch = %p ch + 1 = %p\n", ch, ch + 1);
	printf("p = %p p + 1 = %p\n", p, p + 1);
	printf("d = %p d + 1 = %p\n", d, d + 1);
	return 0;
}
