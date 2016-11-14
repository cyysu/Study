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
	char path[128];
	int i;

	int ret;

	umask(0);
	ret = creat(argv[1], 0755);

	printf("ret = %d\n", ret);

	//umask 0022 => filemode
    /*
	 *umask(0);
	 *fd = open("./test", O_WRONLY | O_CREAT, 0777);
     */

	for (i = 0; i < 3; i++)
	{
		snprintf(path, sizeof(path), "./test/file_%d", i + 1);
		/*fd = open(path, O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);*/
		/*fd = open(path, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);*/
		/*fd = open(path, O_WRONLY | O_CREAT, 777);*/
		/*sleep(1);*/
	}
	return 0;
}
