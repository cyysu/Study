
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
#include <time.h>
#include <dirent.h>
#include <glob.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define ERRP(con, func, ret) do{							\
							if (con)						\
							{								\
								printf(#func" failed!\n");	\
								ret;						\
							}								\
						}while(0)
#define SHOW 3
#define INPUT 10

int main(int argc, char **argv)
{
	char buf[128];
	int fdr, fdw;
	int ret;
	// 1 创建有名管道
	mkfifo("ztol", 0666);//表示张三给李斯发送消息
	mkfifo("ltoz", 0666);

	// 2 打开文件
	
	fdr = open("ztol", O_RDWR);
	ERRP(fdr == -1, "open read", goto ERR1);
	fdw = open("ltoz", O_RDWR);
	ERRP(fdw == -1, "open write", goto ERR2);

	
	//3 创建进程
	system("clear");
	if (fork() == 0)
	{
		//show
		while(1)
		{
			ret = read(fdr, buf, sizeof(buf));
			ERRP(ret <= 0, "read date", goto ERR3);
			printf("\033[%d;1HZHANGSAN : \033[K%s\033[u", SHOW, buf);
			fflush(NULL);
			if (!strcmp(buf, "exit"))
			{
				break;
			}
		}
		exit(0);
	}
	else
	{
		//intput
		while(1)
		{
			printf("\033[%d;1HLISI ： \033[s\033[K", INPUT);
			fgets(buf, sizeof(buf), stdin);
			if (buf[strlen(buf) - 1] == '\n')
				buf[strlen(buf) - 1] = '\0';
			write(fdw, buf, strlen(buf) + 1);
			if (!strcmp(buf, "exit"))
			{
				break;
			}
		}
	}

	wait(NULL);

	unlink("ztol");
	unlink("ltoz");

	return 0;
ERR3:
	close(fdw);
ERR2:
	close(fdr);
ERR1:
	unlink("ztol");
	unlink("ltoz");
	return -1;	
}
