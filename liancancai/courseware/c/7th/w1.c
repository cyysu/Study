#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*char buf[] = "0123456789abcdef";*/

void scale(int num, int bit)
{
	if (num == 0)
	{
		return ;
	}
	scale(num / bit, bit);
	putchar("0123456789ABCDEF"[num % bit]);

}
int main(void)
{
	int num, bit;

	printf("please input num and bit : ");
	scanf("%d%d", &num, &bit);
	
	scale(num, bit);	
	putchar(10);
	return 0;
}
