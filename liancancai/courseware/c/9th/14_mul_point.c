#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a = 10;// &a a
	int *p = &a;// &p p *p
	int **q = &p;// &q q *q **q
	int ************v = NULL;

	printf("sizeof(q) = %d\n", sizeof(q));
	printf("sizeof(v) = %d\n", sizeof(v));
    /*
	 *q = &a;
	 *printf("&q = %p q = %p *q= %p\n", &q, q, *q);
     */
	
	printf("&a = %p a = %d\n", &a, a);
	printf("&p = %p p = %p *p = %d\n", &p, p, *p);
	printf("&q = %p q = %p *q= %p **q = %d\n", &q, q, *q, **q);
	return 0;
}
