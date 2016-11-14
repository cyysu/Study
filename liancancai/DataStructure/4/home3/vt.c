#include "vt.h"
#include <stdio.h>

void gotoxy(int x, int y)
{
	printf("\033[%d;%dH", x, y);
}
void putch(char ch, int fcolor, int bcolor)
{
	printf("\033[%d;%dm%c\033[0m", fcolor, bcolor, ch);
}
void putstr(char *s, int fcolor, int bcolor)
{
	printf("\033[%d;%dm%s\033[0m", fcolor, bcolor, s);
}
void move_up(int bit)
{
	printf("\033[%dA", bit);
}
void move_down(int bit)
{
	printf("\033[%dB", bit);
}
void move_left(int bit)
{
	printf("\033[%dD", bit);
}
void move_right(int bit)
{
	printf("\033[%dC", bit);
}
void save_cur(void)
{
	printf("\033[s");
}
void load_cur(void)
{
	printf("\033[u");
}
void hide_cur(void)
{
	printf("\033[?25l");
}
void show_cur(void)
{
	printf("\033[?25h");
}
//表示画竖线
void draw_hline(int x, int y, int len, char ch, int fcolor)
{
	int i;
	for (i = 0; i < len; i++)
	{
		gotoxy(x + i, y);
		printf("\033[%dm%c\033[0m", fcolor, ch);
	}
}
//表示画直线
void draw_vline(int x, int y, int len, char ch, int fcolor)
{
	int i;
	gotoxy(x, y);
	for (i = 0; i < len; i++)
	{
		printf("\033[%dm%c\033[0m", fcolor, ch);
	}
}
//表示画实体
void draw_rect(int x, int y, int h, int w, int color, char ch)
{
	int i, j;
	for (i = 0; i < h; i++)
	{
		gotoxy(x + i, y);
		for (j = 0; j < w; j++)
		{
			printf("\033[%dm%c\033[0m", color, ch);
		}
		putchar(10);
	}
}
//表示画盒子
void draw_box(int x, int y, int h, int w, int color, char ch)
{
	int i, j;
	for (i = 0; i < h; i++)
	{
		gotoxy(x + i, y);
		for (j = 0; j < w; j++)
		{
			if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
			{
				printf("\033[%dm%c\033[0m", color, ch);
			}
			else
			{
				putchar(' ');
			}
		}
		putchar(10);
	}

}
