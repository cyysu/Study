#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	//fopen(path, mode) => open()
    /*
	 *printf("O_RDONLY = %d\n", O_RDONLY);
	 *printf("O_WRONLY = %d\n", O_WRONLY);
	 *printf("O_RDWR = %d\n", O_RDWR);
	 *printf("S_IRWXU = %o\n", S_IRWXU);
     */

	int fd;

	/*close(0);*/
	/*close(1);*/
	/*close(2);*/
	while(1)
	{
		fd = open(argv[1], O_RDONLY);//表示只读 表示程序对文件操作
		if (fd == -1)
		{
			printf("open failed!\n");
			break;
		}
		printf("fd = %d\n", fd);
	}

	printf("open success!\n");
	printf("count = %d\n", getdtablesize());

	/*printf("fd = %d\n", open(argv[2], O_RDONLY));*/
	close(fd);

	return 0;
}
