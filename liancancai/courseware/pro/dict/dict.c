#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "llist.h"
#include "vt.h"

#define ESC     27
#define BACK    127
#define ENTER   10
#define ERROR   -1

#define LEN     20
#define MAX     8 

struct word_t {
    char *en;
    char *cn;
};

int d = 0;

int get_key(void)
{
    char ch[8];

    if (read(0, ch, 8) == 1)
        return ch[0];
    return -1;
}

void destroy(const void *data)
{
    struct word_t *val = (struct word_t *)data;
    free(val->en);
    free(val->cn);
}

LLIST *dict_init(const char *path)
{
    LLIST *handle = NULL;
    FILE *fp = NULL;
    char buf[1024], *val = NULL;
    int flag = 1;
    struct word_t word;

    fp = fopen(path, "r");
    ERR(NULL == fp, goto ERR1);

    handle = llist_create(sizeof(struct word_t));
    ERR(NULL == handle, goto ERR2);

    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = '\0';

        val = (char *)malloc(strlen(buf) + 1);
        ERR(NULL == val, goto ERR3);
        strcpy(val, buf);

        if (flag)
            word.en = val; 
        else
        {
            word.cn = val;
            ERR(llist_append(&word, handle) != 0, goto ERR4);
        }
        flag = !flag;
    }
    
    fclose(fp);

    system("stty -echo");
    system("stty -icanon");
    clean(0);
    gotoxy(1, 1);
    printf("please search key : ");
    fflush(stdout);

    return handle;
ERR4:
    free(word.cn);
ERR3:
    if (!flag)
        free(word.en);
    llist_destroy(handle, destroy); 
ERR2:
    fclose(fp);
ERR1:
    return NULL;
}

void dict_exit(LLIST *handle)
{
    llist_destroy(handle, destroy);
    gotoxy(13, 1);
    system("stty echo");
    system("stty icanon");
}

int cmp_len(const void *d1, const void *d2)
{
    return strncmp(d1, ((struct word_t *)d2)->en, strlen(d1));
}

int cmp_en(const void *d1, const void *d2)
{
    return strcmp(d1, ((struct word_t *)d2)->en);
}

void show_en(const void *data, void *args)
{
    if (d++ < MAX)
        printf("%s\n", (*((struct word_t **)data))->en);
}

void find_word(char *key, LLIST *handle)
{
    LLIST *find = NULL;
    int i;
    
    find = llist_findall(key, cmp_len, handle);
    if (find != NULL)
    {
        save_cur();
        for (i = 0; i < MAX; i++)
        {
            gotoxy(4 + i, 1);
            clean(1); 
        }
        gotoxy(4, 1);
        llist_travel(show_en, NULL, find);
        d = 0;
        load_cur();
        llist_destroy(find, NULL);
    }
}

void find_cn(char *key, LLIST *handle)
{
    struct word_t *find;
    find = llist_find(key, cmp_en, handle);
    if (find != NULL)
    {
        save_cur();
        gotoxy(2, 1);
        clean(1);
        printf("\ten: %s\n", find->en);
        clean(1);
        printf("\tcn: %s", find->cn);
        load_cur();
    }
}

int main(void)
{
    int key, quit = 0, i = 0;
    char buf[LEN + 1];
    LLIST *handle = NULL;

    handle = dict_init("./ciku.dict");
    ERR(NULL == handle, goto ERR1);

    while (!quit)
    {
        key = get_key();

        switch (key)
        {
            case ESC:
                quit = 1;
                break;
            case BACK:
                if (i < 1)
                    break;
                move_left(1);
                putch(10, 10, ' ');
                move_left(1);
                i--;
                buf[i] = '\0';
                find_word(buf, handle);
                break;
            case ENTER:
                buf[i] = '\0';
                find_cn(buf, handle);
                gotoxy(1, 21);
                clean(2);
                i = 0;
                break;
            case ERROR:
                break;
            default:
                if (i >= LEN)
                    break;
                putchar(key);
                buf[i++] = key;
                buf[i] = '\0';
                find_word(buf, handle);
                break;
        }
        save_cur();
        gotoxy(13, 1);
        printf("buf = %s, i = %2d", buf, i);
        load_cur();
        fflush(stdout);
    }

    dict_exit(handle);
    
    return 0;
ERR1:
    fprintf(stderr, "dict load failed!\n");
    return 0;
}
