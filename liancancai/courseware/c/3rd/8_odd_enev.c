#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num, i;
	int count = 0;

	printf("please input number : ");
	scanf("%d", &num);

	for (i = 31; i >= 0; i--)
	{
		if (((num >> i) & 1) == 1)
		{
			count++;
		}
	}
	if (count % 2 == 0)
	{
		printf("偶校验!\n");
	}
	else
	{
		printf("奇校验!\n");
	}
	return 0;
}
