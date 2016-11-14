#include "fri.h"

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
