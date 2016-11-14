#include "stack.h"
#include "vt.h"

#define MAX 300

#define RED 31
#define BGK 47
#define BLUE 34
#define DELAY 100000

enum direction{up, down, left, right, error, ok};//0 1 2 3 5 6

int dir(char bkg[][21], int *i, int *j)
{
	if(' ' == bkg[*i - 1][*j])
	{
		*i -= 1;
		return up;
	}
	else if(' ' == bkg[*i + 1][*j])
	{
		*i += 1;
		return down;
	}
	else if(' ' == bkg[*i][*j - 1])
	{
		*j -= 1;
		return left;
	}
	else if(' ' == bkg[*i][*j + 1])
	{
		*j += 1;
		return right;
	}
	else
	{
		return error;
	}
}

int win(char bkg[][21], int *i, int *j)
{
	if('S' == bkg[*i - 1][*j])
	{
		return ok;
	}
	else if('S' == bkg[*i + 1][*j])
	{
		return ok;
	}
	else if('S' == bkg[*i][*j - 1])
	{
		return ok;
	}
	else if('S' == bkg[*i][*j + 1])
	{	
		return ok;
	}
	else
	{
		return -1;
	}
}

void ls_int(void *data)
{	
	int *i = (int *)data;
	printf("%d\n", *i);
}

int main(void)
{
	int i, j;
	STACK *stack_hang = NULL;//行
	STACK *stack_lie = NULL;//列

	stack_hang = stack_create(MAX, sizeof(int));
    stack_lie = stack_create(MAX, sizeof(int));

    int hang = 0, lie = 0;

    int temp_old = -1, temp_new = -1;
	char bkg[11][21]={	"#####################",
						"##E##################",
						"##       #       ####",
						"##   # #   ####     #",
						"### ## ##    ########",
						"###      #        ###",
						"###  ###### #####   #",
						"###   ##    ##    ###",
						"####  # ####    #####",
						"#####   #    #      S",
						"#####################"			
					 };

	for(i = 0; i < 11; i++)
	{
		for(j = 0; j < 21; j++)
		{
			if(bkg[i][j] == 'E')
			{
					hang = i;
					lie = j;
			}
		}
	}

	stack_push(&hang, stack_hang);
	stack_push(&lie, stack_lie);

	system("clear");
	for(i = 0; i < 11; i++)
	{
		for(j = 0; j < 21; j++)
		{
			gotoxy(i, j);
			putch(bkg[i][j], RED, 0);
		}
	}

	while(1)
	{	
		
		gotoxy(hang, lie);
		putch('G', RED, BGK);

		temp_new = win(bkg, &hang, &lie);
		if(ok == temp_new)
		{		
			gotoxy(25, 25);
			putchar(10);
			printf("OK! \n");
			break;
		}

		bkg[hang][lie] = '#';
		temp_new = dir(bkg, &hang, &lie);

		if(error == temp_new)
		{
			hang = *(int *)stack_pop(stack_hang);
			lie = *(int *)stack_pop(stack_lie);
			gotoxy(hang, lie);
			putch('B', BLUE, BGK);
		}	
		else if(win == temp_new)
		{
			printf("OK!\n");
		}
		else
		{
			stack_push(&hang, stack_hang);
			stack_push(&lie, stack_lie);
		}

		gotoxy(13, 1);
		putchar(10);

		usleep(DELAY);
	}
	return 0;
}
