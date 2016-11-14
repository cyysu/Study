#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num;
	float result;

	printf("please input air number : ");
	scanf("%d", &num);

	if (num >= 3 && num < 5)
	{
		result = 1999 * num * 0.95;
	}
	else if (num >= 5 && num < 10)
	{
		result = 1999 * num * 0.9;
	}
	else if (num >= 10 && num < 15)
	{
		result = 1999 * num * 0.85;
	}
	else if (num >= 15 && num < 20)
	{
		result = 1999 * num * 0.8;
	}
	else if (num >= 20)
	{
		result = 1999 * num * 0.7;
	}
	else
	{
		result = 1999 * num;
	}

	printf("用户购买了 %d 台，总价格 %.2f 元!\n",num, result);
	return 0;
}
