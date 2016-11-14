#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//实现两个数交换
int main(void)
{
	int a = 1, b = 2;
	int tmp;

	printf("before : a = %d b = %d\n",a, b);
	tmp = a;
	a = b;
	b = tmp;
	printf("after  : a = %d b = %d\n",a, b);
	printf("================\n");
	
	printf("before : a = %d b = %d\n",a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("after  : a = %d b = %d\n",a, b);
	printf("================\n");
	
	printf("before : a = %d b = %d\n",a, b);
    /*
	 *a = a ^ b;
	 *b = a ^ b;
	 *a = a ^ b;
     */
	a ^= b;
	b ^= a;
	a ^= b;
	printf("after  : a = %d b = %d\n",a, b);
	return 0;
}
