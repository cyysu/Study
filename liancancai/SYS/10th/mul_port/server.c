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

#define PORT 1111

int main(int argc, char **argv)
{
	int ret;
	int sockfd;
	int len;
	int optval = 1;
	struct sockaddr_in sockaddr ,from;
	char buf[128] = {};
	struct ip_mreqn m;

	// 1 建立套接字 
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	ERRP(-1 == sockfd, socket, goto ERR1);
	
	//端口复用
	ret = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
	ERRP(-1 == ret, setsockopt, goto ERR2);

	m.imr_multiaddr.s_addr = inet_addr("226.11.22.33");//组ip
	m.imr_address.s_addr = inet_addr(argv[1]);//添加用户ip，就是本机ip
	m.imr_ifindex = 0;

	ret = setsockopt(sockfd,  IPPROTO_IP, IP_ADD_MEMBERSHIP, &m, sizeof(m));
	ERRP(-1 == ret, setsockopt, goto ERR1);

	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(PORT);
	sockaddr.sin_addr.s_addr = INADDR_ANY;

	len = sizeof(sockaddr);

	ret = bind(sockfd, (struct sockaddr *) &sockaddr, len);
	ERRP(-1 == ret, bind, goto ERR2);

	while(1)
	{
		ret = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &from, &len);
		printf("%s\n", buf);
		printf("port = %d\n", ntohs(from.sin_port));
		printf("ip = %s\n", inet_ntoa(from.sin_addr));
		printf("\n");
		memset(buf, 0, sizeof(buf));
	}

	return 0;
ERR2:
	close(sockfd);
ERR1:
	return -1;
}
