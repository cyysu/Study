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
	int ret;
	char buf[128];

	ret = mkfifo(argv[1], 0666);
	if (ret == -1)
	{
		printf("mkfifo failed!\n");
		return -1;
	}

	printf("mkfifo success!\n");

	//打开文件
	int fd;
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		unlink(argv[1]);
		return -1;
	}

	if (fork() == 0)
	{
		write(fd, "hello", 5);
		close(fd);
		exit(0);
	}

	wait(NULL);
	read(fd, buf, sizeof(buf));
	printf("buf = %s\n", buf);

	close(fd);
	unlink(argv[1]);
	return 0;
}
