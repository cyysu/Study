#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//定义枚举类型 枚举常量
enum num{one = 2, two, three = 100, four, five};
enum weekday{sun, mon, tue, wed, thu, fri, sat};

int main(void)
{
	enum num num1 = one;
	/*one = 3;*/
	enum weekday today;

	one = 3;

	printf("sizeof(enum num) = %d\n", sizeof(enum num));
	printf("sizeof(enum weekday) = %d\n", sizeof(enum weekday));
	printf("please input weekday : ");
	scanf("%d", &today);
		
	switch (today)
	{
		case sun:
			printf("sunday!\n");
			break;
		case mon:
			printf("monday!\n");
			break;
		case tue:
			printf("tuesday!\n");
			break;
		default :
			printf("error!\n");
			break;
	}
	num1 = 10 + one;

	printf("num1 = %d\n", num1);
	printf("one = %d\n", one);
	printf("two = %d\n", two);
	printf("five = %d\n", five);
	return 0;
}
