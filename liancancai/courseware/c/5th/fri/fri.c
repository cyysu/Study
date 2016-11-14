#include "fri.h"

//判断是否是闰年
int is_year(int year)
{
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
		return 1;
	return 0;
}
//统计年总天数
int count_year_days(int sy, int ey)
{
	int i;
	int days = 0;
	for (i = sy; i < ey; i++)
	{
		days += 365 + is_year(i);
	}

	return days;
}

int count_month_days(int month, int year)
{
	int i, days = 0;

	for (i = 1; i < month; i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10)
		{
			days += 31;
		}
		if (i == 2)
		{
			days += 28 + is_year(year);
		}
		if (i == 4 || i == 6 || i == 9 || i == 11)
		{
			days += 30;
		}
	}
	return days;
}
