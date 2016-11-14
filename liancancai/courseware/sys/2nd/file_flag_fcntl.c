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
	int flag;

	fd = open(argv[1], O_WRONLY | O_CREAT);
	if (fd == -1)
	{
		return -1;
	}

	printf("O_CREAT = %#o\n", O_CREAT);
	flag = fcntl(fd, F_GETFL);
	if (flag == -1)
	{
		return -1;
	}
	printf("fd = %d\n", fd);
	printf("flag = %#o\n", flag);

	flag |= O_APPEND;
	printf("flag = %#o\n", flag);

	
	flag = fcntl(fd, F_SETFL, flag);
	write(fd, "test program", 12);
	close(fd);
	return 0;
}
