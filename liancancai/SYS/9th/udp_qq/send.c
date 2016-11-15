#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <shadow.h>
#include <crypt.h>
#include <time.h>
#include <dirent.h>
#include <glob.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include "vt.h"

#define INFORMATION   do{					\
		printf("file: %s\n", __FILE__);		\
		printf("func: %s\n", __func__);		\
		printf("line: %d\n", __LINE__);		\
}while(0)

#define ERRP(condition, string, ret) do{	\
		if(condition)						\
		{									\
			printf(#string" failed\n");		\
			INFORMATION;					\
			ret;							\
		}									\
}while(0)

//write info_one
//read info_two

//两个问题
//1　调用fgets时　如何换行
//2 在pintf 后面调用gotoxy不执行
int main(int argc, char **argv)
{
	char buf[128] = {};
	int ret;
	int fd;
	char *pret = NULL;

	system("clear");

	draw_box(1, 1, 14, 50, 31, '+');
	draw_vline(15, 1, 50, '=', 32);

	gotoxy(16, 2);//跳到输入处

	ret = fork();
	ERRP(-1 == ret, fork, goto ERR1);

	if (0 == ret)//child write info_one
	{
		umask(0);

		ret = mkfifo("./info_one", 755);

		fd = open("./info_one", O_RDWR);

		ERRP(-1 == fd, open, goto ERR1);

		while(1)
		{
			gotoxy(16, 1);//跳到输入处
			pret = fgets(buf, sizeof(buf), stdin);
			ERRP(NULL == pret, fgets, goto ERR1);

			if (buf[strlen(buf) - 1] == '\n')
			{
				buf[strlen(buf) -1 ] = '\0';
			}

			del_cur(16, 0);//删除当前的字符串

			ret = write(fd ,buf, sizeof(buf));
			ERRP(-1 == ret, write, goto ERR1);
			usleep(1000);
		}
		close(fd);

		exit(0);
	}
	else//parents read info_two
	{
		int count = 1;
		umask(0);

		ret = mkfifo("./info_two", 755);

		fd = open("./info_two", O_RDWR);

		ERRP(-1 == fd, open, goto ERR1);

		while(1)
		{
			ret = read(fd ,buf, sizeof(buf));
			ERRP(-1 == ret, write, goto ERR1);

			count ++;
			if (count == 14)
			{
				system("clear");

				draw_box(1, 1, 14, 50, 31, '+');
				draw_vline(15, 1, 50, '=', 32);

				count = 2;
			}
			gotoxy(count, 2);

			printf("%s\n", buf);
			gotoxy(15, 1);
			printf("\n");//加上这句　gotoxy(15, 1)才会执行

			usleep(1000);
			load_cur();
		}
		close(fd);

	}

	return 0;
ERR1:
	return -1;
}
