#include "vt.h"

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

int location(int x ,int y, int num)
{
	int ret, k, i, j;
	char buf[8];

	i = x;
	j = y;

	/*printf("x = %d  y = %d \n", x, y);*/
	/*system("stty echo icanon");*/
	gotoxy(i, j);
	getchar();
	while(1)
	{
		ret = read(0, buf, sizeof(buf));

		/*fflush(NULL);*/
		/*memset(buf, 0, sizeof(buf));*/
		
		if(ret == -1)
			return -1;
		else if(buf[0] == 27 && ret == 1)
		{
			return;
		}
		else if(buf[0] == 49 || i + 0 == x && buf[0] == 10)
			return 1;
		else if(buf[0] == 50 || i + 1 == x && buf[0] == 10)
			return 2;
		else if(buf[0] == 51 || i + 2 == x && buf[0] == 10)
			return 3;
		else if(buf[0] == 52 || i + 3 == x && buf[0] == 10)
			return 4;
		else if(buf[0] == 53 || i + 4 == x && buf[0] == 10)
			return 5;
		else if(buf[0] == 54 || i + 5 == x && buf[0] == 10)
			return 6;
		else if(buf[0] == 55 || i + 6 == x && buf[0] == 10)
			return 7;
		else if(buf[0] == 'w' || buf[2] == 65)
		{
			x--;
			if(x < i)
			{
				gotoxy(i + num, j);
				x = i + num - 1;
			}
			printf("\033[A");
		}
		else if(buf[0] == 's' || buf[2] == 66)
		{
			x++;
			if(x > i + num - 1)
			{
				x = i;
				gotoxy(i - 1, j);
			}
			printf("\033[B");
		}
		else
			return 0;	//返回错误

		fflush(NULL);
		memset(buf, 0, sizeof(buf));
			
	}
}

void stu_ui(void)
{
	draw_box(7, 50, 3, 50, 32, '#');
	gotoxy(8, 63);
	putstr("****学 生 界 面****\n", 34, 49);
}

void tea_ui(void)
{
	draw_box(7, 50, 3, 50, 32, '#');
	gotoxy(8, 63);
	putstr("****老 师 界 面****\n", 34, 49);
}

void admin_ui(void)
{
	draw_box(7, 50, 3, 50, 32, '#');
	gotoxy(8, 63);
	putstr("****管 理 员 界 面****\n", 34, 49);
}
