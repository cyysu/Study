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
	int fd;
	int ret, i;
	char buf[128];
	int count = 1000;

	fd = open("./test", O_RDWR | O_CREAT | O_TRUNC);
	if (fd == -1)
	{
		return -1;
	}
	ret = fork();
	if (ret == -1)
	{
		return -1;
	}
	else if (ret == 0)
	{
		//child
		sleep(2);
		printf("ppid = %d\n", getppid());
		printf("child : pwd = %s\n", get_current_dir_name());
		for(i = 0; i < count; i++)
		{
			snprintf(buf, sizeof(buf), "%d : child : getpid = %d\n", i + 1, getpid());
			write(fd, buf, strlen(buf));
		}
		close(fd);
	}
	else
	{
		//parent
		/*sleep(1);*/
		printf("parent : pwd = %s\n", get_current_dir_name());

		for (i = 0; i < count; i++)
		{
			snprintf(buf, sizeof(buf), "%d : parent : getpid = %d\n", i + 1, getpid());
			write(fd, buf, strlen(buf));
		}
		close(fd);
	}
	return 0;
}
