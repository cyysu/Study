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

#define PORT 10000
#define IP "192.168.0.103"
#define LISTEN_NUM 50

int main(int argc, char **argv)
{
	int ret;
	int sockfd;
	int len;
	int src_sockfd;
	struct sockaddr_in src, from;
	char read_buf[256] = {};
	char write_buf[256] = {};
	// 1 建立套接字
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	ERRP(-1 == sockfd, socket, goto ERR1);
	// 2 绑定端口ip
	// struct sockaddr_in {
 //               sa_family_t    sin_family; /* address family: AF_INET */
 //               in_port_t      sin_port;   /* port in network byte order */
 //               struct in_addr sin_addr;   /* internet address */
 //           };

 //           /* Internet address. */
 //           struct in_addr {
 //               uint32_t       s_addr;     /* address in network byte order */
 //           };
	src.sin_family = AF_INET;
	src.sin_port = htons(atoi(argv[1]));
	src.sin_addr.s_addr = inet_addr(IP); 

	len = sizeof(struct sockaddr_in);

	// ret = bind(sockfd, (struct sockaddr *) &src, &len);
	ret = bind(sockfd, (struct sockaddr *) &src, len);
	ERRP(-1 == ret, bind, goto ERR2);
	// 3 监听

	ret = listen(sockfd, LISTEN_NUM);
	ERRP(-1 == ret, listen, goto ERR2);
	// 4 建立连接 
	 // int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

	src_sockfd = accept(sockfd, (struct sockaddr *) &from, &len);
	ERRP(-1 == src_sockfd, accept, goto ERR2);

	// printf("src_sockfd = %d\n", src_sockfd);


	// 5 接收数据
	ret = fork();

	if(0 == ret)//child 接受数据
	{
		while(1)
		{
			// ret = read(src_sockfd, read_buf, sizeof(read_buf));
			ret = recv(src_sockfd, read_buf, sizeof(read_buf), 0);
			ERRP(-1 == ret, read, goto ERR2);

			// if(strcmp(read_buf, "exit") == 0)
			// {
			// 	break;
			// }

			printf("read_buf = %s\n", read_buf);

			memset(read_buf, 0, sizeof(read_buf));
		}
	}
	else //parents 发送数据
	{
		while(1)
		{
			fgets(write_buf, sizeof(write_buf), stdin);

			if (write_buf[strlen(write_buf) - 1] == '\n')
			{
				write_buf[strlen(write_buf) - 1] = '\0';
			}
			
			if(strcmp(write_buf, "exit") == 0)
			{
				break;
			}

			// write(src_sockfd, write_buf, sizeof(write_buf));
			send(src_sockfd, write_buf, sizeof(write_buf), 0);
		}
	}
	
	close(sockfd);
	close(src_sockfd);

	return 0;
ERR2:
	close(sockfd);
ERR1:
	return -1;
}
