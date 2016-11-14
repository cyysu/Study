#include "func.h"


void game_stat(void)
{
	int quit = 0, option;
	int top = 3, high = 5, line = 5;
	while(!quit)
	{
		system("clear");//清屏函数
		printf("======>   menu  <======\n");
		printf("=> 1 input triangle  <=\n");
		printf("=> 2 input trapezoid <=\n");
		printf("=> 3 set top and high<=\n");
		printf("=> 4 exit            <=\n");

		printf("please input option : ");
		scanf("%d", &option);
		switch (option)
		{
			case 1:
				tri_sub_menu(line);
				break;
			case 2:
				printf("top = %d high = %d\n", top, high);
				trapezoid(top, high);
				break;
			case 3:
				printf("please input top and high : ");
				scanf("%d%d", &top, &high);
				break;
			case 4:
				quit = 1;
				break;
			default :
				printf("option err!\n");
				break;
		}
	getchar();
	}
}

void tri_sub_menu(int line)
{
	int quit = 0, option;
	system("clear");

	while (!quit)
	{
		system("clear");
		printf("===> triangle <===\n");
		printf("=> 1 left up    <=\n");
		printf("=> 2 left down  <=\n");
		printf("=> 3 right up   <=\n");
		printf("=> 4 right down <=\n");
		printf("=> 5 exit       <=\n");
		printf("please input option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				left_up(line);
				break;
			case 2:
				left_down(line);
				break;
			case 3:
				right_up(line);
				break;
			case 4:
				right_down(line);
				break;
			case 5:
				quit = 1;
				break;
			default:
				printf("option sub err!\n");
				break;
		}
	getchar();
	getchar();
	}
}
void left_up(int line)
{
	printf("left_up!\n");
}
void left_down(int line)
{
	printf("left_down!\n");
}
void right_up(int line)
{
	printf("right_up!\n");
}
void right_down(int line)
{
	printf("right_down!\n");
}
void trapezoid(int top, int high)
{

}
void game_end(void)
{
	printf("game over!\n");
}
