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

//实现UDP的客户端
int main(int argc, char **argv)
{
	int sd;
	int ret;

	//1 创建套接子
	sd = socket(PF_INET, SOCK_DGRAM, 0);
	if (sd == -1)
	{
		printf("socket failed!\n");
		return -1;
	}


	int fd;
	char ch;
	fd = open("/etc/passwd", O_RDONLY);
	if (fd == -1)
	{
		return -1;
	}


	//2 发送数据
	struct sockaddr_in to;
	to.sin_family = AF_INET;
	to.sin_port = htons(9999);
	to.sin_addr.s_addr = inet_addr("10.1.1.72");


	while(read(fd, &ch, 1) == 1)
	{
		ret = sendto(sd, &ch, 1, 0, (struct sockaddr *)&to, sizeof(to));
		if (ret == -1)
		{
			printf("sendto failed!\n");
			return -1;
		}
		usleep(200000);
	}

	close(fd);
	close(sd);
	return 0;
}
