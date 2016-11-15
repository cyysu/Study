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

int main(int argc, char **argv)
{
	int ret;
	int sockfd;
	int len;
	struct sockaddr_in dest;
	char read_buf[256] = {};
	char write_buf[256] = {};
	// 1 创建套接字
	// int socket(int domain, int type, int protocol);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	ERRP(-1 == sockfd, socket, goto ERR1);

	// 2 请求建立链接
	 // int connect(int sockfd, const struct sockaddr *addr,
  //                  socklen_t addrlen);
	// struct sockaddr_in {
	// 	sa_family_t    sin_family; /* address family: AF_INET */
	// 	in_port_t      sin_port;   /* port in network byte order */
	// 	struct in_addr sin_addr;   /* internet address */
	// };

	// /* Internet address. */
	// struct in_addr {
	// 	uint32_t       s_addr;     /* address in network byte order */
	// };

	dest.sin_family = AF_INET;
	// uint16_t htons(uint16_t hostshort);

	dest.sin_port = htons(atoi(argv[1]));

	// 192.168.0.103
	dest.sin_addr.s_addr = inet_addr(IP);

	len = sizeof(dest);

	ret = connect(sockfd,(struct sockaddr *) &dest, len);
	// strerror(errno);
	// printf("error: %s\n", strerror(errno));
	// PRT_ERROR;
	ERRP(-1 == ret, connect, goto ERR2);

	ret = fork();

	if(0 != ret)// parents
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
				// printf("break\n");
				break;
			}

			write(sockfd, write_buf, sizeof(write_buf));
		}
	}
	else//child
	{
		while(1)
		{
			ret = read(sockfd, read_buf, sizeof(read_buf));
			ERRP(-1 == ret, read, goto ERR2);

			// if(strcmp(read_buf, "exit") == 0)
			// {
			// 	break;
			// }

			printf("read_buf = %s\n", read_buf);

			memset(read_buf, 0, sizeof(read_buf));
		}
	}

	close(sockfd);

	return 0;
ERR2:
	close(sockfd);
ERR1:
	return -1;
}
