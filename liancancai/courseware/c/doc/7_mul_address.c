#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a[2][3] = {1,2};

	//	&a
	// 	a
	//	a[0]

	printf("&a = %p\n", &a);
	printf("a = %p\n", a);
	printf("a[0] = %p\n", a[0]);
	printf("&a[0][0] = %p\n", &a[0][0]);
	return 0;
}
