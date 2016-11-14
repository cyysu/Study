#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fd1, fd2, fd3;

	fd1 = creat(argv[1], 0666);
	if (fd1 == -1)
	{
		return -1;
	}

	
	/*fd2 = creat(argv[1], 0666);*/
	fd2 = dup(fd1);

	printf("fd1 = %d fd2 = %d\n", fd1, fd2);
	write(fd1, "hello", 5);
	write(fd2, "world", 5);
	close(fd1);
	close(fd2);

	//标注输出 1
	/*close(1);*/

	write(1, "hello\n", 6);
	fd3 = dup(1);
	write(fd3, "world\n", 6);

	write(fd3, "world\n", 6);
	write(1, "world\n", 6);
	return 0;
}
