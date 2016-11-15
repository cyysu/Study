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

#define IP "192.168.0.103"
#define PORT 1111
int main(int argc, char **argv)
{
	int ret;
	int sockfd, src_sockfd;
	int len;
	char buf[256] = {};

	struct sockaddr_in src, from;
	// struct sockaddr_in from;

	// 1 创建套接字
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	ERRP(-1 == sockfd, socket, goto ERR1);
	// 2 绑定端口, IP
	len = sizeof(src);

	src.sin_family = AF_INET;
	// src.sin_port = htons(atoi(argv[1]));
	src.sin_addr.s_addr = inet_addr(IP);

	// ret = bind (sockfd, (struct sockaddr *) &src, len);
	// ERRP(-1 == ret, bind, goto ERR2);

	// 3 接收数据
       // ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
       //                  struct sockaddr *src_addr, socklen_t *addrlen);
	ret = fork();

	if(0 == ret)//child reveive
	{
		// src.sin_port = htons(atoi(argv[1]));
		src.sin_port = htons(PORT + 1);

		ret = bind (sockfd, (struct sockaddr *) &src, len);
		ERRP(-1 == ret, bind, goto ERR2);

		while(1)
		{
			memset(buf, 0, sizeof(buf));
			ret = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &src, &len);
			ERRP(ret == -1, recvfrom, goto ERR2);

			if(strcmp(buf, "exit") == 0)
			{
				break;
			}

			printf("buf = %s\n", buf);
			// fflush(NULL);
		}
	}
	else//parents send
	{
		src.sin_port = htons(PORT);
	
		while(1)
		{
			fgets(buf, sizeof(buf), stdin);

			if(buf[strlen(buf) -1] == '\n')
			{
				buf[strlen(buf) -1] = '\0';
	 		}

	 		if(strcmp(buf, "exit") == 0)
	 		{
	 			close(sockfd);
	 			break;
	 		}

	 		// src.sin_port = htons(atoi(argv[1]));	


			ret = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &src, len);
			ERRP(ret <=0, sendto, goto ERR2);
		}
	}

	close(sockfd);

	return 0;
ERR2:
	close(sockfd);
ERR1:
	return -1;
}
