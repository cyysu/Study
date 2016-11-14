#include "stack.h"

#define ROW 10
#define COL 20

//# 表示墙
//@ 表示走过路
//不可以越界
//定义坐标
struct pos_t{
	int x;
	int y;
};

//表示四个方向 上 下 左 右
struct pos_t dir[4] = { {-1, 0},
						{1, 0},
						{0, -1},
						{0, 1}};

void show(char (*map)[COL])
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		printf("%s\n", map[i]);
	}
}

//获取坐标
struct pos_t get_pos(char ch, char (*map)[COL])
{
	int i, j;
	struct pos_t cur = {-1, -1};

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (map[i][j] == ch)
			{
				cur.x = i;
				cur.y = j;
				return cur;
			}
		}
	}
	return cur;
}
int main(void)
{
	int i;
	STACK *handle = NULL;
	struct pos_t stat, end, sel, val;
	struct pos_t *cur = NULL;
	char map[ROW][COL] = {
					"#S#################",
					"#  ###  #####  ####",
					"# ##    #       # #",
					"# ## #### ## ## ###",
					"# ##    # ##  #  ##",
					"#     #    ##### ##",
					"## #########     ##",
					"## ###  ##   ######",
					"##     #####   #  #",
					"#################E#",
					};

	/*cur = (struct pos_t *)malloc(sizeof(struct pos_t));*/

	system("clear");
	show(map);
	handle = stack_create(ROW * COL, sizeof(struct pos_t));
	ERRP(handle == NULL, stack_create, goto ERR1);

	
	stat = get_pos('S', map);
	end = get_pos('E', map);

	stack_push(&stat, handle);//起点
	getchar();
	while(1)
	{
		system("clear");
		cur = (struct pos_t *)stack_pop(handle);
		if (cur == NULL)
		{
			printf("no exit!\n");
			return -1;
		}
		
		val = *cur;	

		if (cur->x == end.x && cur->y == end.y)
		{
			break;
		}

		
		map[cur->x][cur->y] = '@';
		show(map);
		/*printf("cur->x = %d cur->y = %d\n", cur->x, cur->y);*/
		fflush(NULL);

		for (i = 0; i < 4; i++)
		{
			sel.x = val.x + dir[i].x;
			sel.y = val.y + dir[i].y;

            /*
			 *printf("sel.x = %d sel.y = %d\n", sel.x, sel.y);
			 *printf("val.x = %d val.y = %d\n", val.x, val.y);
			 *printf("==========\n");
             */
			if (sel.x < 0 || sel.x > ROW - 1 || sel.y < 0 || sel.y > COL - 1 || map[sel.x][sel.y] == '#' || map[sel.x][sel.y] == '@')
			{
				continue;
			}
			/*printf("sel.x = %d sel.y = %d\n", sel.x, sel.y);*/

			stack_push(&sel, handle);
		}
		usleep(200000);
		/*getchar();*/
	}


	stack_destroy(handle);
    /*
	 *printf("stat.x = %d stat.y = %d\n", stat.x, stat.y);
	 *printf("end.x = %d end.y = %d\n", end.x, end.y);
     */
	return 0;
ERR1:
	return -1;
}


