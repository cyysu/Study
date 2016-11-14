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

#define SHOW 3
#define INPUT 10

#define PORT 12345

//服务器
int main(int argc, char **argv)
{
	int sd, fd;
	int ret;

	//1 创建套接子
	sd = socket(PF_INET, SOCK_STREAM, 0);
	if (sd == -1)
	{
		return -1;
	}
	
	//2 帮定端口和ip地址
	struct sockaddr_in src, from;
	src.sin_family = AF_INET;
	src.sin_port = htons(PORT);//表示服务端口
	src.sin_addr.s_addr = htonl(INADDR_ANY);//表示服务ip地址

	ret = bind(sd, (struct sockaddr *)&src, sizeof(src));
	if (ret == -1)
	{
		printf("bind failed!\n");
		close(sd);
		return -1;
	}

	//3 监听
	ret = listen(sd, 20);
	if (ret == -1)
	{
		printf("listen failed!\n");
		return -1;
	}

	int len = sizeof(from);
	char buf[128];
	fd = accept(sd, (struct sockaddr *)&from, &len);
	if (fd == -1)
	{
		printf("accept failed!\n");
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
			ret = read(fd, buf, sizeof(buf));
			if (ret <= 0)
			{
				break;
			}
			fprintf(stderr, "\033[%d;1HSHOW : \033[K%s\033[u", SHOW, buf);
			if (strcmp(buf, "bye") == 0)
			{
				break;
			}
			memset(buf, 0, sizeof(buf));//清空buf

		}
		close(fd);
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
			ret = write(fd, buf, strlen(buf));
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
	wait(NULL);
	close(fd);
	close(sd);
	return 0;
}
