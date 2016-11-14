#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//能被400整除 或者 能被4整除且不可以被100整除
int main(void)
{
	int a = 324, b =324;
	int max;
	int year;

	printf("please input year : ");
	scanf("%d", &year);

	printf("year = %d\n", year);

	(year % 400 == 0 || year % 4 == 0 && year % 100 != 0) ? printf("yes!\n") : printf("no!\n"); 

/*
 *    printf("please input a and b : ");
 *    scanf("%d%d", &a, &b);
 *
 *    printf("a = %d b = %d\n", a, b);
 */

	max = a > b ? a : b;

	printf("max = %d\n",max);
	return 0;
}
