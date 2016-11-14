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
	int ret, fd;

	// 1 创建管道文件
	ret = mkfifo("./ken", 0666);
	
	//2 打开管道文件
	fd = open("./ken", O_RDWR);
	if (fd == -1)
	{
		unlink("./ken");
		return -1;
	}
	//3 发送数据
	ret = write(fd, argv[1], strlen(argv[1]) + 1);
	if (ret <= 0)
	{
		printf("write failed!\n");
		close(fd);
		unlink("ken");
		return -1;
	}

	// 4关闭文件
	close(fd);
	unlink("ken");


	
	return 0;
}
