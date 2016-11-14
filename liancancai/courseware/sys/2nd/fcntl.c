#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fd, fd1;

	fd = open(argv[1], O_WRONLY);
	if (fd == -1)
	{
		return -1;
	}

	printf("fd = %d\n", fd);
	//复制文件描述符
	//F_DUPFD

	//fd1 = dup(fd)  dup2(old, new)
	fd1 = fcntl(fd, F_DUPFD, 1);
	/*dup2(fd, 1);*/
	if (fd1 == -1)
	{
		printf("fcntl failed!\n");
		return -1;
	}
	//file_flag(fd);
	write(1, "hello", 5);
	write(fd, "hello", 5);
	printf("this is stdout!\n");

	printf("fd1 = %d\n", fd1);

	close(fd);
	return 0;
}
