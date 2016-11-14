#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vt.h"

#define ROW 12
#define COL 40
#define NUM 3

struct ball_t{
	int x;
	int y;
	int x_inc;
	int y_inc;
	int color;
	int h;
	int w;
	char ch;
};

void move(struct ball_t *ball)
{
	if (ball->x < 2 || ball->x + ball->h > ROW)
	{
		ball->color = rand() % 7 + 31;
		ball->x_inc = -ball->x_inc;
	}
	if (ball->y < 2 || ball->y + ball->w > COL)
	{
		ball->color = rand() % 7 + 31;
		ball->y_inc = -ball->y_inc;
	}
	ball->x += ball->x_inc;
	ball->y += ball->y_inc;
}

void test(struct ball_t *ball)
{
	int i;
	for (i = 0; i < NUM; i++)
	{
		draw_rect(ball[i].x, ball[i].y, ball[i].h, ball[i].w, ball[i].color, ball[i].ch);
	}
}
int main(void)
{
	system("clear");
	int i;
	struct ball_t ball[NUM] =  {{3, 3, 1, 1, 31, 2, 4, '@'},
								{5, 9, -1, -1, 32, 3, 5, '$'},
								{2, 20, 1, -1, 33, 5, 7, '%'}};
	hide_cur();
	while(1)
	{
		gotoxy(1, 1);
		draw_box(1, 1, ROW, COL, 10, '#');
		test(ball);
		for (i = 0; i < NUM; i++)
			move(&ball[i]);
		usleep(200000);
		fflush(NULL);
	}
	show_cur();

	return 0;
}
