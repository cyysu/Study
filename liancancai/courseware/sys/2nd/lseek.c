#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int ret;
	int fd;
	char buf[128];

	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC);
	/*fd = open(argv[1], O_RDONLY);*/
	if (fd == -1)
	{
		return -1;
	}

	ret = lseek(fd, (long long)1024 * 1024 * 1024, SEEK_SET);
    /*
	 *ret = lseek(fd, -1, SEEK_END);
	 *ret = lseek(fd, 0, SEEK_CUR);
     */
	if (ret == -1)
	{
		printf("lseek failed!\n");
		return -1;
	}

	printf("ret = %d\n", ret);

	write(fd, "hello", 5);

    /*
	 *read(fd, buf, sizeof(buf));
	 *printf("buf = %s\n", buf);
     */
	return 0;
}
