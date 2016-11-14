#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void gotoxy(int x, int y)
{
	printf("\033[%d;%dH", x, y);
}

int main(void)
{
	gotoxy(10, 10)
	return 0;
}
