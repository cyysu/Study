#ifndef __KEN_VT_H__
#define __KEN_VT_H__

void gotoxy(int x, int y);
void putch(char ch, int fcolor, int bcolor);
void putstr(char *s, int fcolor, int bcolor);
void move_up(int bit);
void move_down(int bit);
void move_left(int bit);
void move_right(int bit);
void save_cur(void);
void load_cur(void);
void hide_cur(void);
void show_cur(void);
void del_cur(int x, int y);
//表示画竖线
void draw_hline(int x, int y, int len, char ch, int fcolor);
//表示画直线
void draw_vline(int x, int y, int len, char ch, int fcolor);
//表示画实体
void draw_rect(int x, int y, int h, int w, int color, char ch);
//表示画盒子
void draw_box(int c, int y, int h, int w, int color, char ch);

#endif 
