#include <stdio.h>
#include <string.h>
#include "vt.h"

#define COL     40

int main(void)
{
    char c[] = "No entry for string in "
               "section 2 of the manual"
               "old character encoding "
               "and/or character setstr"
               "str locate a substringc"
               "ompared. both arguments"
               ".These functions return"
               "a pointer to the beginn"
               "ing of the substring, o" 
               "tion is a non-standard "
               "extension.";
    int i, l = 0, speed = 0, e = 0;
    long long st, et; 
    char err[strlen(c)];
    char ch;
    
    clean(); 
    gotoxy(1, 1);
    for (i = 0; i < strlen(c); i++)
    {
        if (i != 0 && i % COL == 0)
        {
            putch(10, 10, '\n');
            l++;
        }
        putch(10, 10, c[i]);
    }

    l += 3;
    gotoxy(l, 1);
    putstr(10, 10, "打字总数：0 个， 错误数：0 个打字速度：0 个/分钟");

    gotoxy(l + 1, 1);
    for (i = 0; i < COL; i++)
    {
        putch(10, 10, '='); 
    }
    gotoxy(l + 2, 1);

    system("stty -echo");
    system("stty -icanon");

    i = 0;

    st = time(NULL);

    while (1)
    {
        ch = getchar(); 
        if (ch == 27)
            break;
        if (ch == 127)
        {
            if (i > 0 && i % COL > 0)
            {
                i--;
                move_left(1);
                putch(10, 10, ' ');
                move_left(1);
                if (err[i] != c[i])
                    e--;
                et = time(NULL);
                speed = i / (float)((et - st) / 60.0);

                save_cur();
                gotoxy(l, 1);
                fprintf(stderr, "\033[2K打字总数：%3d 个 错误数：%3d 个 打字速度：%3d 个/分钟", i, e, speed);
                load_cur();
            }
            continue; 
        }
        
        err[i] = ch;

        if (c[i] == ch)
            putch(34, 10, ch);
        else
        {
            putch(31, 10, ch);
            e++;
        }
        i++;

        if (i == strlen(c))
            break;

        if (i % COL == 0 && i != 0)
            putch(10, 10, '\n');

        et = time(NULL);
        speed = i / (float)((et - st) / 60.0);

        save_cur();
        gotoxy(l, 1);
        fprintf(stderr, "\033[2K打字总数：%3d 个 错误数：%3d 个 打字速度：%3d 个/分钟", i, e, speed);

        load_cur();
    }

    system("stty echo");
    system("stty icanon");
    
    return 0;
}
