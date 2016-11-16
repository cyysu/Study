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

int main(int argc, char **argv)
{
	int sd;
	int ret;
	char buf[5];

	//1 创建套接子
	sd = socket(PF_INET, SOCK_DGRAM, 0);
	if (sd == -1)
	{
		return -1;
	}

	//表示设置端口重用。
	int val = 1;
	ret = setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
	if (ret == -1)
	{
		printf("setsockopt failed!\n");
		return -1;
	}
	// 2 帮定端口和ip
	struct sockaddr_in src, from;
	src.sin_family = AF_INET;
	src.sin_port = htons(9999);
	src.sin_addr.s_addr = INADDR_ANY;

	ret = bind(sd, (struct sockaddr *)&src, sizeof(src));
	if (ret == -1)
	{
		printf("bind failed!\n");
		return -1;
	}
	// 3 接受数据
	int len = sizeof(from);
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		ret = recvfrom(sd, buf, sizeof(buf), 0, (struct sockaddr *)&from, &len);
		if (ret == -1)
		{
			printf("recvfrom failed!\n");
			return -1;
		}
		printf("%s", buf);
		fflush(NULL);
	}
	close(sd);
	return 0;
}
