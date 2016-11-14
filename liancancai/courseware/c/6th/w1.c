#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//time(null) => 1970 1 1  格林时间
//2016年 09月 26日 星期一 10:01:52 CST

#define BASE 1970

//求总天数
int base_days(void)
{
	return ((time(NULL) / 60 / 60) + 8) / 24;
}

//判断是否是闰年
int is_year(int year)
{
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
		return 1;
	return 0;
}
//求今年年份
int now_year(void)
{
	int year = BASE;
	int days = base_days();
	
	while(days > 365)
	{
		if (is_year(year) && days == 366)
		{
			break;
		}
		days -= 365 + is_year(year++);
	}

	return year;
}

//统计年总天数
int count_year_days(int sy,int ey)
{
	int i;
	int days = 0;
	for (i = sy; i < ey; i++)
	{
		days += 365 + is_year(i);
	}
	return days;
}
//求今年月份
int now_month(void)
{
	int month = 1;
	int days = base_days() - count_year_days(BASE, now_year());

	while(days > 28)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 ||month == 8 || month == 10)
		{
			days -= 31;
		}
		if (month == 2)
		{
			days -= 28 + is_year(now_year());
		}
		if (month == 4 ||month == 6 || month == 9 || month == 11)
		{
			days -= 30;
		}
		month++;
	}

	return month;
}
//求月总天数
int count_month_days(int month, int year)
{
	int i;
	int days = 0;
	for (i = 1; i < month; i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 ||i == 8 || i == 10)
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
//求天数
int now_days(void)
{
	return base_days() - count_year_days(BASE,now_year()) - count_month_days(now_month(), now_year()) + 1;
}
//求星期
int now_weeks(void)
{
	int week = base_days() % 7;
	// 4 -> 1
	// 5 -> 2
	// 6 -> 3
	// 0 -> 4
	// 1 -> 5
	// 2 -> 6
	// 3 -> 0

	if (week < 4)
		return week + 4;
	return week - 3;
}

void pri_weeks(void)
{
	
}
int main(void)
{
	printf("days = %d\n", base_days());
	printf("year = %d\n", now_year());
	printf("month = %d\n", now_month());
	printf("days = %d\n", now_days());
	printf("week = %d\n", now_weeks());
	printf("hours = %d\n", ((time(NULL) / 60 / 60) + 8)% 24);
	printf("minutes = %d\n", (time(NULL) / 60) % 60);
	printf("seconds = %d\n", time(NULL) % 60);
	return 0;
}
