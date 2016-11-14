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


#define PORT 12345

//客户端
int main(int argc, char **argv)
{
	int sd;
	int ret;

	//1 创建套接子
	sd = socket(PF_INET, SOCK_STREAM, 0);
	if (sd == -1)
	{
		printf("socket failed!\n");
		return -1;
	}

	printf("sd = %d\n", sd);
	printf("success!\n");

	// 2 发送请求建立链接
	struct sockaddr_in dest;
	dest.sin_family = AF_INET;
	dest.sin_port = htons(PORT);
	dest.sin_addr.s_addr = inet_addr(argv[1]);

	ret = connect(sd, (struct sockaddr *)&dest, sizeof(dest));
	if (ret == -1)
	{
		printf("connect failed!\n");
		close(sd);
		return -1;
	}

	// 3 发送数据
	ret = write(sd, argv[2], strlen(argv[2]) + 1);
	if (ret <= 0)
	{
		printf("write failed!\n");
		close(sd);
		return -1;
	}
	
	char buf[128];

	read(sd, buf, sizeof(buf));
	printf("client_message  :  %s\n", buf);

	printf("connect success!\n");
	//4 关闭套接子
	close(sd);
	return 0;
}
