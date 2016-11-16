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
#include <crypt.h>
#include <time.h>
#include <dirent.h>
#include <glob.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <arpa/inet.h>
#include <errno.h>
extern int errno;

#define INFORMATION   do{					\
		printf("file: %s\n", __FILE__);		\
		printf("func: %s\n", __func__);		\
		printf("line: %d\n", __LINE__);		\
}while(0)

#define ERRP(condition, string, ret) do{	\
		if(condition)						\
		{									\
			printf(#string" failed\n");		\
			INFORMATION;					\
			ret;							\
		}									\
}while(0)

#define PRT_ERROR (printf("error: %s\n", strerror(errno)))

#define IP 192.168.0.104
#define PORT 1111
//客户端
int main(int argc, char **argv)
{
	int sockfd;
	int ret;
	int len;
	char buf[128];
	struct sockaddr_in sockaddr;
	int optval = 1;
	int count = 1;
	// 1 建立套接字
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	ERRP(-1 == sockfd, socket, goto ERR1);

	//设置多播
	ret = setsockopt(sockfd,  IPPROTO_IP, IP_MULTICAST_LOOP, &optval, sizeof(optval));
	ERRP(-1 == ret, setsockopt, goto ERR1);

	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(PORT);

	sockaddr.sin_addr.s_addr = inet_addr("226.11.22.33");//这里要写多播的IP

	len = sizeof(sockaddr);
	// 2 发送数据

	while(1)
	{
		snprintf(buf, sizeof(buf), "hello = %d", count++);

		ret = sendto(sockfd, buf, sizeof(buf), 0,(struct sockaddr *) &sockaddr, len);
		ERRP(ret <= 0, snedto, goto ERR2);

		// printf("ggg\n");
		sleep(1);
	}

	close(sockfd);

	return 0;
ERR2:
	close(sockfd);
ERR1:
	return -1;
}
