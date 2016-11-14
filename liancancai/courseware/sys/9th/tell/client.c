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
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>

#define SHOW 3
#define INPUT 10


#define PORT 12345

//客户端
int main(int argc, char **argv)
{
	int sd;
	int ret;
	char buf[128] = {};

	//1 创建套接子
	sd = socket(PF_INET, SOCK_STREAM, 0);
	if (sd == -1)
	{
		printf("socket failed!\n");
		return -1;
	}

	// 2 发送请求建立链接
	struct sockaddr_in dest;
	dest.sin_family = AF_INET;
	dest.sin_port = htons(PORT);
	dest.sin_addr.s_addr = inet_addr("10.1.1.72");

	ret = connect(sd, (struct sockaddr *)&dest, sizeof(dest));
	if (ret == -1)
	{
		printf("connect failed!\n");
		close(sd);
		return -1;
	}

	system("clear");
	if (fork() == 0)
	{
		//read
		fprintf(stderr, "\033[%d;1HSHOW : ", SHOW);
		while(1)
		{
			ret = read(sd, buf, sizeof(buf));
			if (ret <= 0)
			{
				break;
			}
			fprintf(stderr, "\033[%d;1HSHOW : \033[K%s\033[u", SHOW, buf);

			if (!strcmp(buf, "bye"))
			{
				break;
			}
			memset(buf, 0, sizeof(buf));//清空buf

		}
		close(sd);
		exit(0);
	}
	else
	{
		//write
		while(1)
		{
			fprintf(stderr, "\033[%d;1HINPUT : \033[K\033[s", INPUT);
			fgets(buf, sizeof(buf), stdin);
			if (buf[strlen(buf) - 1] == '\n')
				buf[strlen(buf) - 1] = '\0';
			ret = write(sd, buf, strlen(buf));
			if (ret <= 0)
			{
				break;
			}
			if (!strcmp(buf, "bye"))
			{
				break;
			}
			memset(buf, 0, sizeof(buf));
		}
	}
	//4 关闭套接子
	wait(NULL);
	close(sd);
	return 0;
}
