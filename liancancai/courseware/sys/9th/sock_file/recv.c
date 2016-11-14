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

#define PORT 12345

struct user_t{
	char name[128];
	char passwd[128];
	int uid;
};
//服务器
int main(int argc, char **argv)
{
	int sd, fd;
	int ret;
	struct user_t user;

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
	/*src.sin_addr.s_addr = inet_addr("10.1.1.72");//表示服务ip地址*/
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
	//4 建立连接
	fd = accept(sd, (struct sockaddr *)&from, &len);
	if (fd == -1)
	{
		printf("accept failed!\n");
		close(sd);
		return -1;
	}
	//5 接受数据
	ret = recv(fd, &user, sizeof(user), 0);
	if (ret == -1)
	{
		printf("recv failed!\n");
		return -1;
	}

	printf("name = %s passwd = %s uid = %d\n", user.name, user.passwd, user.uid);
	close(fd);
	close(sd);
	return 0;
}
