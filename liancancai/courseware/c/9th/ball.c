#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vt.h"

#define ROW 12
#define COL 40

int x = 3, y = 4, h = 5, w = 8, color = 31, x_inc = 1, y_inc = 1;
char ch = '@';

void move(void)
{
	if (x < 2 || x + h > ROW)
	{
		color = rand() % 7 + 31;
		x_inc = -x_inc;
	}
	if (y < 2 || y + w > COL)
	{
		color = rand() % 7 + 31;
		y_inc = -y_inc;
	}
	x += x_inc;
	y += y_inc;
}
int main(void)
{
	system("clear");

	hide_cur();
	while(1)
	{
		gotoxy(1, 1);
		draw_box(1, 1, ROW, COL, 10, '#');
		draw_rect(x, y, h, w, color, ch);
		move();
		usleep(200000);
		fflush(NULL);
	}
	show_cur();

	return 0;
}
