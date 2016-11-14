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

int main(int argc, char **argv)
{
	/*daemon(0, 0);*/

	// 1 创建孤儿进程
	if (fork())
	{
		printf("parnet : pid = %d ppid = %d gpid = %d sid = %d\n", getpid(), getppid(), getpgrp(), getsid(getpid()));
		exit(0);
	}

	//2 创建新的会话
	setsid();

	//3 改变进程工作目录
	chdir("/");
	//4 
	umask(0);
	//5 关闭文件描述符
	int i;
	for (i = 0; i < 1024; i++)
	{
		close(i);
	}
/*
 *    sleep(1)
 *    printf("child : pid = %d ppid = %d gpid = %d sid = %d\n", getpid(), getppid(), getpgrp(), getsid(getpid()));
 *
 *    printf("pwd  = %s\n", get_current_dir_name());
 */

	while(1)
		;
	return 0;
}
