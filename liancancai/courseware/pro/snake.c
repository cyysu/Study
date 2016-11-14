#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#define ROW     12
#define COL     50

#define ESC     27
#define SPACE   32
#define UP      65
#define DOWN    66
#define LEFT    68
#define RIGHT   67

char bg[ROW][COL];
int x = 3, y = 3, direct = RIGHT, level = 1;
int fx, fy;
int sx[100] = {3, 2, 1, 1, 1};
int sy[100] = {3, 3, 3, 2, 1};
int count = 5;

void start_timer(int level);
void stop_timer(void);
void snake_init(char (*bg)[COL], int x, int y, void (*action)(int), int *fx, int *fy, int *sx, int *sy, int count);
void snake_exit(void);
int get_input(void);
void init(char (*bg)[COL], int c, int fx, int fy);
void draw(char (*bg)[COL], int x, int y, int *sx, int *sy, int count);
void display(char (*bg)[COL]);
void move(int *x, int *y, int direct, int *fx, int *fy, int *sx, int *sy, int *count, int *level);
void action(int);
void snake_change(int *sx, int *sy, int count, int x, int y);

void init(char (*bg)[COL], int c, int fx, int fy)
{
    int i, j;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++) 
        {
            if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1) 
                bg[i][j] = c;
            else
                bg[i][j] = ' ';
        }
    }
    bg[fx][fy] = '*';
}

void draw(char (*bg)[COL], int x, int y, int *sx, int *sy, int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (i == 0)
            bg[sx[i]][sy[i]] = '@';
        else
            bg[sx[i]][sy[i]] = '0';
    }
}
void display(char (*bg)[COL])
{
    int i, j;

    printf("\033[1;1H");
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++) 
        {
            printf("%c", bg[i][j]); 
        }
        printf("\n");
    }
    fflush(stdout);
}

void snake_change(int *sx, int *sy, int count, int x, int y)
{
    memmove(sx + 1, sx, count * sizeof(int));
    memmove(sy + 1, sy, count * sizeof(int));
    sx[0] = x;
    sy[0] = y;
}

void move(int *x, int *y, int direct, int *fx, int *fy, int *sx, int *sy, int *count, int *level)
{
    int i;

    if (*x - 1 < 0 || *x + 1 > ROW - 1 || *y - 1 < 0 || *y + 1 > COL - 1)
        snake_exit();

    for (i = 1; i < *count; i++)
    {
        if (*x == sx[i] && *y == sy[i]) 
            snake_exit();
    }

    if (*x == *fx && *y == *fy)
    {
        sx[*count] = *fx;
        sy[*count] = *fy;
        *count += 1;
        *fx = rand() % (ROW - 2) + 1;
        *fy = rand() % (COL - 2) + 1;
        if (*level < 10)
        {
            *level += 1;
            start_timer(*level);
        }
    }

        
    switch (direct)
    {
        case UP:
            *x -= 1;
            break;
        case DOWN:
            *x += 1;
            break;
        case LEFT:
            *y -= 1;
            break;
        case RIGHT:
            *y += 1;
            break;
        default:
            break;
    }
    snake_change(sx, sy, *count, *x, *y);
}

void snake_init(char (*bg)[COL], int x, int y, void (*action)(int), int *fx, int *fy, int *sx, int *sy, int count)
{
    *fx = rand() % (ROW - 2) + 1;
    *fy = rand() % (COL - 2) + 1;
    
    init(bg, '#', *fx, *fy);
    draw(bg, x, y, sx, sy, count);

    signal(SIGALRM, action);

    printf("\033[2J\033[?25l");
    system("stty -echo");
    system("stty -icanon");
    display(bg);
}

void snake_exit(void)
{
    printf("\033[%d;1H\033[?25h", ROW + 2);
    system("stty echo");
    system("stty icanon");
    exit(0);
}

int get_input(void)
{
    int key = -1, ret;
    char ch[8];

    /*ret = read(STDIN_FILENO, ch, 8);*/
    ret = read(0, ch, 8);
    if (ret == 1)
        key = ch[0];
    else if (ret == 3 && ch[0] == 27 && ch[1] == 91)  
        key = ch[2];

    return key;
}

void start_timer(int level)
{
    struct itimerval it;

    it.it_interval.tv_sec = 0;
    it.it_interval.tv_usec = (10 - level) * 50000;
    it.it_value.tv_sec = 0;
    it.it_value.tv_usec = 1000;
    
    setitimer(ITIMER_REAL, &it, NULL);
}

void stop_timer(void)
{
    struct itimerval it;
    memset(&it, 0, sizeof(it));
    setitimer(ITIMER_REAL, &it, NULL);
}

void action(int sig)
{
    init(bg, '#', fx, fy);
    move(&x, &y, direct, &fx, &fy, sx, sy, &count, &level);
    draw(bg, x, y, sx, sy, count);
    display(bg);
}

int main(void)
{
    int key, quit = 0, flag = 1;

    snake_init(bg, x, y, action, &fx, &fy, sx, sy, count);
    
    while (!quit)
    {
        key = get_input();
        switch (key)
        {
            case ESC:
                quit = 1;
                break;
            case SPACE:
                if (flag)
                    start_timer(level);
                else
                    stop_timer();
                flag = !flag;
                break;
            case UP:
                if (direct != DOWN)
                    direct = UP;
                break;
            case DOWN:
                if (direct != UP)
                    direct = DOWN;
                break;
            case LEFT:
                if (direct != RIGHT)
                    direct = LEFT;
                break;
            case RIGHT:
                if (direct != LEFT)
                    direct = RIGHT;
                break;
            default:
                break;
        }
    }

    snake_exit();
    
    return 0;
}
