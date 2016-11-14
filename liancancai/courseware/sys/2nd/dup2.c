#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	
	// 0 1 2
	int fd;

	fd = open("./temp", O_WRONLY);
	printf("fd = %d\n", fd);

	/*close(2);*/

	write(1, "hello", 5);
	write(fd, "world", 5);

    /*
	 *dup2(1, fd);
	 *write(fd, "test", 4);
     */
	dup2(1, 8);
	write(8, "tttt", 4);
	putchar(10);

sleep(1);
	fd = open("./temp", O_WRONLY);
	printf("fd = %d\n", fd);


	return 0;
}
