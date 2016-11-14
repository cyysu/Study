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
int main(void)
{
	int i, days = 0, d;
	int year = 2016, month;
	//统计年总天数 1990 2016

/*
 *    printf("please input year : ");
 *    scanf("%d", &year);
 *
 *    days =count_year_days(1900, year) + 13;//表示13号
 *    
 *    for (i = 1; i <= 12; i++)
 *    {
 *        d = days + count_month_days(i, year);
 *        if (d % 7 == 5)
 *        {
 *            printf("%d 月13日是黑色星期五！\n", i);
 *        }
 *
 *    }
 */

	printf("please input year : month : days : ");
	scanf("%d %d %d", &year, &month, &d);
	days = count_year_days(2000, year) + count_month_days(month, year)+ d - 1;
	if (days % 5 < 3)
	{
		printf("打鱼!\n");
	}
	else
	{
		printf("晒网!\n");
	}
	return 0;
}
