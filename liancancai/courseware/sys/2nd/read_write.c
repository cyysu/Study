#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fd;
	char buf[128];
	int ret;

	fd = open(argv[1], O_RDWR);//表示读写模式
	if (fd == -1)
	{
		return -1;
	}

	memset(buf, 0, sizeof(buf));//清空buf

	write(fd, "tom", 3);

	ret = read(fd, buf, sizeof(buf) - 1);
	if (ret <= 0)
	{
		close(fd);
		return -1;
	}

	printf("buf = %s\n", buf);
	return 0;
}
