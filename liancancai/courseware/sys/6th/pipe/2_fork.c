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


int main(int argc, char **argv)
{
	int fd[2], ret, pid;
	char buf[128];

	//1 创建管道
	ret = pipe(fd);
	if (ret == -1)
	{
		return -1;
	}
	//2 创建进程
	if ((pid = fork()) == 0)
	{
		//child -> wirte
		/*write(fd[1], argv[1], strlen(argv[1]) + 1);*/
		sleep(1);
		read(fd[0], buf, sizeof(buf));
		printf("buf = %s\n", buf);
		close(fd[0]);
		close(fd[1]);
		exit(0);
	}
	else if (pid == -1)
	{
		return -1;
	}

	//parnet -> read;
	/*read(fd[0], buf, sizeof(buf));*/
	write(fd[1], "child", 5);
	printf("buf = %s\n", buf);
	wait(NULL);
	close(fd[0]);
	close(fd[1]);
	return 0;
}
