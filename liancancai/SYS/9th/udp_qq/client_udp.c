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
	int sockfd;
	struct sockaddr_in dest;
	char buf[256] = {};
	int len;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);//创建套接字
	ERRP(-1 == sockfd, socket, goto ERR1);

	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = inet_addr(IP);

	len = sizeof(dest);

	system("clear");

	draw_box(1, 1, 14, 50, 31, '+');//绘制边框
	draw_vline(15, 1, 50, '=', 32);

	gotoxy(16, 2);//跳到输入处

	ret = fork();

	if(0 != ret)//parents send
	{
		dest.sin_port = htons(atoi(argv[1]) + 1);//设置端口号
		while(1)
		{
			gotoxy(16, 1);//跳到输入处

			fgets(buf, sizeof(buf), stdin);//键盘输入

			if(buf[strlen(buf) -1] == '\n')
			{
				buf[strlen(buf) -1] = '\0';
	 		}

	 		del_cur(16, 0);//删除当前的字符串

	 		if(strcmp(buf, "exit") == 0)//输入exit退出
	 		{
	 			close(sockfd);
	 			break;
	 		}

			ret = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &dest, len);//发送数据
			ERRP(ret == -1, sendto, goto ERR2);
		}
	}
	else //child receive
	{
		int count = 1;

		dest.sin_port = htons(atoi(argv[1]));//

		ret = bind (sockfd, (struct sockaddr *) &dest, len);//绑定端口IP
		ERRP(-1 == ret, bind, goto ERR2);

		while(1)
		{
			memset(buf, 0, sizeof(buf));
			ret = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &dest, &len);//接收到的数据
			ERRP(ret == -1, recvfrom, goto ERR2);

			count ++;
			if (count == 14)//当满屏时，清空并从头开始显示
			{
				system("clear");

				draw_box(1, 1, 14, 50, 31, '+');
				draw_vline(15, 1, 50, '=', 32);

				count = 2;
			}
			gotoxy(count, 2);

			printf("%s\n", buf);
			gotoxy(15, 1);
			printf("\n");//加上这句　gotoxy(15, 1)才会执行
		}
	}

	return 0;
ERR2:
	close(sockfd);
ERR1:
	return -1;
}
