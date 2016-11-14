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
#include <sys/shm.h>

void do_work(int fd)
{
	char buf[128];
	int i, j, count = 0;
	/*printf("work_pid : %d\n", getpid());*/

	
	for (j = 1; j <= 100; j++)
	{
		snprintf(buf, sizeof(buf), "child : pid = %d count = %d\n", getpid(), count++);
		for (i = 0; i < strlen(buf); i++)
		{
			write(fd, &buf[i], 1);
		}
	}
	close(fd);
	exit(0);
}
int main(int argc, char **argv)
{
	int i;
	int fd;

	fd = open("./test", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		return -1;
	}

	for (i = 0; i < 10; i++)
	{
		if (fork() == 0)
		{
			do_work(fd);
		}
	}

	for (i = 0; i < 10; i++)
	{
		wait(NULL);
	}
	return 0;
}
