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
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include<sys/sem.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/select.h>

int main(int argc, char **argv)
{
	int ret;
	int fd;

	fd_set fdr;
	char buf[128] = {};

	struct timeval t;
	t.tv_sec = 10;
	t.tv_usec = 0;

	//标准输入获取 0
	//从文件获取 管道文件 fd

	mkfifo("./ken", 0777);

	fd = open("./ken", O_RDWR);//访问方式
	if (fd == -1)
	{
		printf("open failed!\n");
		return -1;
	}
	printf("fd = %d\n", fd);

	while(1)
	{
		FD_ZERO(&fdr);
		FD_SET(0, &fdr);
		FD_SET(fd, &fdr);

		ret = select(fd + 1, &fdr, NULL, NULL, &t);
		if (ret == -1)
		{
			printf("slect failed!\n");
			return -1;
		}
		else if (ret == 0)
		{
			printf("time out!\n");
			break;
		}
		else if (ret > 0)
		{
			if (FD_ISSET(fd, &fdr))
			{
				read(fd, buf, sizeof(buf));
				puts(buf);
				memset(buf, 0, sizeof(buf));
			}
			else
			{
				read(0, buf, sizeof(buf));
				puts(buf);
				memset(buf, 0, sizeof(buf));
			}
			/*printf("ret = %d\n", ret);*/
		}
	}
	unlink("./ken");

	return 0;
}
