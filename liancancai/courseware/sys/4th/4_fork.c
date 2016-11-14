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

int main(int argc, char **argv)
{
	int ret;

	//创建一个进程
	ret = fork();
	if (ret == -1)
	{
		printf("fork failed!\n");
		return -1;
	}
	else if (ret == 0)
	{
		//子进程运行
		printf("child!\n");
		printf("child : ret = %d\n", ret);
		printf("child_pid : pid = %d ppid = %d\n", getpid(), getppid());
		printf("============\n");
	}
	else
	{
		//父进程运行
		printf("parent!\n");
		printf("parent : ret = %d\n", ret);//子进程进程号
		printf("parnet_pid : pid = %d ppid = %d\n", getpid(), getppid());
	}

	/*printf("pid = %d : hello!\n", getpid());*/
	return 0;
}
