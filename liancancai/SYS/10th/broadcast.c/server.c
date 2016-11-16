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

//服务器端
int main(int argc, char **argv)
{
	int ret;
	int len;
	int sockfd;
	int optval = 1;
	struct sockaddr_in sockaddr;
	char buf[128] = {};


	// //建立套接字
	// sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	// ERRP(-1 == sockfd, socket, goto ERR1);

	// //设置端口重用
	//      // int setsockopt(int sockfd, int level, int optname,
 //      //                 const void *optval, socklen_t optlen);
	// ret = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
	// ERRP(-1 == ret, setsockopt, goto ERR2);


	//       // int bind(int sockfd, const struct sockaddr *addr,
 //       //          socklen_t addrlen);
	// len = sizeof(sockfd);

	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(PORT);
	sockaddr.sin_addr.s_addr = INADDR_ANY;

	// ret = bind(sockfd, (struct sockaddr *) &sockaddr, len);//绑定端口和ip
	// // PRT_ERROR;
	// ERRP(-1 == ret, bind, goto ERR2);


// 1 建立套接字 
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	ERRP(-1 == sockfd, socket, goto ERR1);
	
	//端口复用
	ret = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
	ERRP(-1 == ret, setsockopt, goto ERR2);


	// sockaddr.sin_family = AF_INET;
	// sockaddr.sin_port = htons(PORT);
	// sockaddr.sin_addr.s_addr = INADDR_ANY;

	len = sizeof(sockaddr);

	ret = bind(sockfd, (struct sockaddr *) &sockaddr, len);
	ERRP(-1 == ret, bind, goto ERR2);





	//接收数据
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		     // ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
       //                  struct sockaddr *src_addr, socklen_t *addrlen);
		ret = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &sockaddr, &len);
		ERRP(-1 == ret, recvfrom, goto ERR2);
	}

	close(sockfd);

	return 0;
ERR2:
	close(sockfd);
ERR1:
	return -1;
}
