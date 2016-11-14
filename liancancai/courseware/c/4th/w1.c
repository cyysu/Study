#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//打印黑色星期五 1900 1 1 => 1
// 星期五 13 2016 1 13
// 1900 ~ 2016 ?  365 366 
// 31 => 1 3 5 7 8 10 12
// 30 => 4 6 9 11
// 2 => 29 28 ?

//% 7  => 0 ~ 6
int main(void)
{
	int i, days = 0;
	int year = 2016;
	//统计年总天数 1990 2016

	printf("please input year : ");
	scanf("%d", &year);

	for (i = 1900; i < year; i++)
	{
		days += 365;
		if (i % 400 == 0 || i % 4 == 0 && i % 100 != 0)
		{
			days += 1;
		}
	}

	/*printf("days = %d\n", days);*/

	days += 13;//表示13号
	
	for (i = 1; i <= 12; i++)
	{
		if (days % 7 == 5)
		{
			printf("%d 月13日是黑色星期五！\n", i);
		}

		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10)
		{
			days += 31;
		}
		if (i == 2)
		{
			days += 28;
			if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
			{
				days += 1;
			}
		}
		if (i == 4 || i == 6 || i == 9 || i == 11)
		{
			days += 30;
		}
	}

	return 0;
}
