#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//汉诺塔

int step = 1;
void move(int num, char from, char to)
{
	printf("第%d步 ：把%d 号盘子从 %c -> %c\n", step++, num, from, to);
}
void hanoi(int num, char from, char on, char to)
{
	if (num == 1)
	{
		move(num, from, to);
	}
	else
	{
		hanoi(num - 1, from, to, on);
		move(num, from, to);
		hanoi(num - 1, on, from, to);
	}
}
int main(void)
{
	hanoi(5, 'A', 'B', 'C');

	return 0;
}
