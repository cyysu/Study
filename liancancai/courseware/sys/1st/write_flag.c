#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	char buf[128];
	int ret;

	/*fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC);*/
	fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND);
	/*fd = open(argv[1], O_RDONLY);*/
	if (fd == -1)
	{
		printf("failed!\n");
		return -1;
	}

	printf("success!\n");

	ret = write(fd, "world", 5);
	if (ret <= 0)
	{
		printf("write failed!\n");
		close(fd);
		return -1;
	}
	ret = read(fd, buf, sizeof(buf));
	if (ret <= 0)
	{
		printf("read failed!\n");
		close(fd);
		return -1;
	}

	printf("ret = %d\n", ret);
	printf("buf = %s\n", buf);
	return 0;
	printf("hello!\n");

	return 0;
}
