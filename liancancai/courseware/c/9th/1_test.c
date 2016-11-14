#include "vt.h"
#include <stdio.h>

int main(void)
{
	gotoxy(10, 10);
	putch('A', 31, 10);
	putstr("hello", 32, 10);
	draw_hline(5, 10, 10, '|', 31);
	draw_vline(5, 10, 10, '-', 32);
	draw_rect(5, 10, 1, 1, 33, '@');
	draw_box(1, 1, 12, 40, 10, '#');
}
