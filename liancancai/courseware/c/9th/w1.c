#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vt.h"

#define ROW 10
#define COL 10

void display(int bg[][COL])
{
	int i, j;

	printf("  ");
	for (i = 0; i < COL; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 0; i < ROW; i++)
	{
		printf("%d ", i);
		for (j = 0; j < COL; j++)
		{
			if (bg[i][j] == 0)
			{
				printf("+ ");
			}
			else if (bg[i][j] == 1)
			{
				printf("A ");
			}
			else if (bg[i][j] == -1)
			{
				printf("B ");
			}
		}
		printf("\n");
	}
}
//检查下子是否合法
int check(int bg[][COL], int x, int y)
{
	//判断是否越界
	if (x < 0 || x > ROW - 1 || y < 0 || y > COL - 1)
	{
		return 1;
	}
	//判断是否有棋子 如果有则返回1 反之返回0
	if (bg[x][y] != 0)
	{
		return 1;
	}

	return 0;
}
//判断输赢
int game_over(int bg[][COL], int x, int y, int flag)
{
	//判断是直线
	int i;
	int count = 0;
	for (i = y - 4; i < y + 4; i++)
	{
		if (i < 0 || i > COL -1)
		{
			continue;
		}
		else if (bg[x][i] == flag)
		{
			count++;
			if (count == 5)
			{
				return 1;
			}
		}
		else 
		{
			count = 0;
		}
	}
	return 0;
}
int main(void)
{
	int bg[ROW][COL] = {};
	int flag = 1;
	int x, y;
	// 1 -> 表示黑棋 A 
	//-1 -> 红棋     B

	while(1)
	{
		system("clear");
		display(bg);
		printf("[ %s ] 下子 : \033[K", flag == 1 ? "黑棋" : "红棋");
		scanf("%d%d", &x, &y);

		//检查棋子是否合法
		if (check(bg, x, y))
		{
			continue;
		}
		bg[x][y] = flag;

		//判断输赢
		if (game_over(bg, x, y, flag))
		{
			system("clear");
			display(bg);
			printf(" %s 赢！\n", flag == 1 ? "黑棋" : "红棋");
			break;
		}

		flag = -flag;
		usleep(200000);
		fflush(NULL);
	}
	return 0;
}
