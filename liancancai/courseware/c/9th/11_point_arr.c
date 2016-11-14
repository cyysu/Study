#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init(int *a)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		a[i] = rand() % 100;
	}
}
int main(void)
{
	int i;
	int a[5] = {1,2,3,4,5};
	int *p = NULL;

	// &a a a[0]
	// &p p *p
	init(a);
	
	p = a;
	printf("p = %p a = %p\n", p, a);
	printf("&p = %p &a = %p\n", &p, &a);

	printf("sizeof(a) = %d\n", sizeof(a));//20
	printf("sizeof(p) = %d\n", sizeof(p));//4
	*(p + 2) = 1122;

	for(i = 0; i < 5; i++)
	{
		printf("%d %d\n", *(a + i), p[i]);
		printf("a[%d] = %d %p %p\n", i, a[i], &a[i], p + i);
		/*printf("p[%d] = %d\n", i, p[i]);*/
		/*printf("p[%d] = %d\n", i, *(p + i));*/
	}
	return 0;
}
