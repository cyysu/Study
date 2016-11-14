#include "vt.h"
#include "llist.h"

#define RED 31
#define BLUE 34

#define HIGH 20
#define WITH 60

// void gotoxy(int x, int y);
// void putch(char ch, int fcolor, int bcolor);
// void putstr(char *s, int fcolor, int bcolor);
// void move_up(int bit);
// void move_down(int bit);
// void move_left(int bit);
// void move_right(int bit);
// void save_cur(void);
// void load_cur(void);
// void hide_cur(void);
// void show_cur(void);
// void del_cur(void);
// //表示画竖线
// void draw_hline(int x, int y, int len, char ch, int fcolor);
// //表示画横线
// void draw_vline(int x, int y, int len, char ch, int fcolor);
// //表示画实体
// void draw_rect(int x, int y, int h, int w, int color, char ch);
// //表示画盒子
// void draw_box(int c, int y, int h, int w, int color, char ch);



int main(int argc, char const *argv[])
{
	// printf("test!\n");

	system("clear");

	draw_hline(2, 2, 20, '|', RED);

	draw_hline(2, 62, 20, '|', RED);

	draw_vline(1, 2, 61, '-', RED);
	// void draw_box(int c, int y, int h, int w, int color, char ch);

	// draw_box(1, 1, HIGH, WITH, RED, '+');
	// draw_vline(3, 2, WITH - 2, '+', BLUE);

	// gotoxy(2,2);
	// printf("1234567890");

	gotoxy(25,1);
	return 0;
}