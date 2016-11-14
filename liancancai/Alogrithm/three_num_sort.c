#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//输入3个数从小到大排列输出

int main(void)
{
	int a, b, c;
	int temp;
	printf("please input therr num:");
	scanf("%d %d %d", &a, &b, &c);

	printf("before : %d, %d, %d\n", a, b, c);

	if(a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}

	if(a > c)
	{
		temp = a;
		a = c;
		c = temp;
	}

	if(b > c)
	{
		temp = b;
		b = c;
		c = temp;
	}

	printf("after: %d, %d, %d\n", a, b, c);

	return 0;
}
