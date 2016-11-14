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
	//创建匿名管道
	int ret;
	int fd[2];
	char buf[128] = {};

	if (open("/etc/passwd", O_RDONLY) == -1)
	{
		printf("open failed!\n");
		return -1;
	}
	ret = pipe(fd);
	if (ret == -1)
	{
		printf("pipe failed!\n");
		return -1;
	}

	printf("pipe success!\n");

	//fd[0] -> read
	//fd[1] -> wite;
	
	ret = write(fd[0], argv[1], strlen(argv[1]) + 1);
	ret = read(fd[1], buf, sizeof(buf));
	/*close(fd[0]);*/
    /*
	 *ret = write(fd[1], argv[1], strlen(argv[1]) + 1);
	 *ret = read(fd[0], buf, sizeof(buf));
     */
	if (ret <= 0)
	{
		printf("read failed!\n");
		close(fd[0]);
		close(fd[1]);
		return -1;
	}
	printf("fd[0] = %d fd[1] = %d\n", fd[0], fd[1]);
	printf("buf = %s\n", buf);

	close(fd[0]);
	close(fd[0]);
	return 0;
}








