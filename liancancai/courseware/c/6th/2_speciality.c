#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int a[5] = {1,2,3,4,5};

	//a 
	
	printf("&a = %p\n", &a);
	printf("&a + 1 = %p\n", &a + 1);

	printf("*&a = %d\n",**&a);

	printf("a = %p\n", a);
	printf("a + 1 = %p\n", a + 1);

	printf("=============\n");
	printf("&a[0] = %p\n", &a[0]);
	printf("&a[0] + 1= %p\n", (char *)&a[0] + 1);


	for (i = 0; i < 5; i++)
	{
		printf("a[%d] = %d %p\n", i, a[i], &a[i]);
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d ", *(a + i));
	}
	printf("\n");

	return 0;
}
