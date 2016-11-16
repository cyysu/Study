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

#define PORT 333

//客户端
int main(int argc, char **argv)
{
	int ret;
	int sockfd;
	int optval = 1;
	struct sockaddr_in sockaddr;
	char buf[128] = {};
	int count = 1;
	int len;

	//建立套接字
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	ERRP(-1 == sockfd, socket, goto ERR1);


	//设置广播
     // int setsockopt(int sockfd, int level, int optname,
     //                  const void *optval, socklen_t optlen);
	ret = setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &optval, sizeof(optval));
	ERRP(-1 == ret, setsockopt, goto ERR2);

	//发送数据
	    // ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
     //                  const struct sockaddr *dest_addr, socklen_t addrlen);
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(PORT);
	// sockaddr.sin_addr.s_addr = INADDR_ANY;
	sockaddr.sin_addr.s_addr = inet_addr("192.255.255.255");//设置广播地址

	len = sizeof(sockaddr);

	while(1)
	{
		snprintf(buf, sizeof(buf), "count = %d\n", count);

		ret = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &sockaddr, len);
		ERRP(-1 == ret, sendto, goto ERR2);

		sleep(1);
	}	

	close(sockfd);

	return 0;
ERR2:	
	close(sockfd);
ERR1:
	return -1;
}

