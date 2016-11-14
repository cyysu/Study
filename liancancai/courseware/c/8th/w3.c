#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROW 15
#define COL 40

void init(char bg[][COL], char ch)
{
    /*
	 *printf("sizeof(bg) = %d\n", sizeof(bg));
	 *printf("sizeof(bg[0]) = %d\n", sizeof(bg[0]));
	 *printf("init!\n");
     */
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1)
			{
				bg[i][j] = ch;
			}
			else
			{
				bg[i][j] = ' ';
			}
		}
	}
}
void show(char bg[][COL])
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%c", bg[i][j]);
		}
		putchar(10);
	}

}
int main(void)
{
	char bg[ROW][COL];
	int x = 3, y = 3, x_inc = 1, y_inc = 1;

	while(1)
	{
		system("clear");
		init(bg, '#');
		bg[x][y] = '@';
		if (x > ROW - 2 || x < 1)
		{
			x_inc = -x_inc;
		}
		if (y > COL - 2 || y < 1)
		{
			y_inc = -y_inc;
		}
		x += x_inc;
		y += y_inc;
		show(bg);
		usleep(100000);
		fflush(NULL);
	}
	return 0;
}
