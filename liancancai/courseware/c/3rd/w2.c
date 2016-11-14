#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//num 0 1 2 4 => 1
//	  7 9 11 12 => 0

//把十进制转换成二进制
void test(int num)
{
	int i;

	for (i = 31; i >= 0; i--)
	{
		if ((i + 1) % 4 == 0)
			putchar(' ');
		printf("%d", (num >> i) & 1);
	}
	printf("\n");
}


int main(void)
{
	int num;

	printf("please input number : ");
	scanf("%d", &num);

	printf("num = %d\n", num);
	test(num);

    /*
	 *num |= 1;
	 *num |= 1 << 1;
	 *num |= 1 << 2;
	 *num |= 1 << 4;
     */
	num |= 1 | 1 << 1 | 1 << 2 | 1 << 4;

	num &= ~(1 << 7 | 1 << 9 | 1 << 6 | 1 << 12);
	test(num);
	return 0;
}
