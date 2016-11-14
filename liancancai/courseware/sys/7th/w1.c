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

// cat /etc/passwd | grep root

int main(int argc, char **argv)
{
	int fd[2];
	//创建匿名管道
	pipe(fd);

	//父子进程

	if (fork() == 0)
	{
		// cat /etc/passwd
		// stdout 1
		close(fd[0]);
		dup2(fd[1], 1);
		execlp("cat", "cat", "/etc/passwd", NULL);//输出终端
		exit(0);
	}

	//grep root
	wait(NULL);
	//stdin 0
	close(fd[1]);
	dup2(fd[0], 0);
	execlp("grep", "grep", "root", NULL);//文件 输入终端
	return 0;
}
