#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void pri(int num)
{
	while(num--)
	{
		printf("* ");
	}
}
void tri(int num)
{
	if (num == 0)
	{
		return ;
	}
	tri(num - 1);
	pri(num);
	printf("\n");
}
int main(void)
{
	tri(5);
	return 0;
}
