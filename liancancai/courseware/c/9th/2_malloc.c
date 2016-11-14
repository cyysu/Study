#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int *p = NULL;

	//&p p;
	p = (int *)malloc(sizeof(int));
	if (p == NULL)
	{
		printf("malloc failed!\n");
		return -1;
	}

	*p = 123;

	printf("&p = %p\n", &p);
	printf("p = %p\n", p);

	printf("*p = %d\n", *p);
	free(p);
	return 0;
}
