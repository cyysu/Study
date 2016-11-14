#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num1, num2;
	int year;
	
	if (!0)
	{
		printf("hello!\n");
	}
	printf("please input year : ");
	scanf("%d", &year);

	if (!(year >= 1000 && year < 10000))
	{
		printf("year format error!\n");
		return -1;
	}
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
	{
		printf("yes!\n");
	}
	else
	{
		printf("no!\n");
	}

	printf("===============\n");
	//2016
	if (!(year % 400))// year % 400 == 0
	{
		printf("yes");
	}
	else
	{
		if (!(year % 4))
		{
			if (year % 100)
			{
				printf("yes!\n");
			}
			else
			{
				printf("no!\n");
			}
		}
		else
		{
			printf("no!\n");
		}
	}

	printf("please input two number : ");
	scanf("%d%d", &num1, &num2);

    /*
	 *if (num > 10);
	 *{
	 *    printf("大于10!\n");
	 *    printf("hello!\n");
	 *}
     */
	if (num1 > num2)
	{
		printf("max = %d\n", num1);
		;
	}
	else
	{
		printf("max = %d\n", num2);
	}
	return 0;
}
