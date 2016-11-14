#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char ch;
	int ret;
	char buf[8];

    /*
	 *system("stty -echo");//关闭回显
	 *system("stty -icanon");//关闭缓冲区
     */
	system("stty -echo -icanon");//关闭缓冲区
	
	while(1)
	{
		ret = read(0, buf, 8);
		if (ret == 1)
		{
			printf("%d | ", buf[0]);
		}
		else if (ret == 2)
		{
			printf("%d %d | ", buf[0], buf[1]);
		}
		else if (ret == 3)
		{
			printf("%d %d %d | ", buf[0], buf[1], buf[2]);
		}
		fflush(NULL);
	}
    /*
	 *while(1)
	 *{
	 *    putchar(getchar());
	 *    fflush(NULL);
	 *}
     */
	system("stty echo");//打开回显
	system("stty icanon");//打开缓冲区
	return 0;
}
