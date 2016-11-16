#define _XOPEN_SOURCE
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
#include <share.h>
//server

int check_passwd(int fd)
{
	int ret;
	char buf[128];

	struct spwd *spd;
	ERRP((spd = getspnam("root")) == NULL, "getspnam", goto ERR1);

	while(1)
	{
		ret = read(fd, buf, sizeof(buf));
		
		printf("buf = %s\n", buf);
		if (!strcmp(crypt(buf, spd->sp_pwdp), spd->sp_pwdp))
		{
			write(fd, "yes", 4);
			break;
		}
		else
		{
			write(fd, "no", 3);
		}
	}
	time_t t = time(NULL);
	char *s = asctime(localtime(&t));
	strcpy(buf, s);
	ERRP((ret = write(fd, buf, strlen(buf) + 1)) <= 0, "write", goto ERR1);

	/*usleep(200000);*/



	return 1;
	return 0;
ERR1:
	return 1;
}

void exec_cmd(int fd)
{
	char buf[128];
	while(1)
	{
		read(fd, buf, sizeof(buf));
		printf("cmd = %s\n", buf);

		chdir("/root");
		dup2(fd, 0);
		dup2(fd, 1);
		dup2(fd, 2);

		execl("/bin/ls", "ls", NULL);

		if (!strcmp(buf, "exit"))
		{
			break;
		}
	}
}
int main(int argc, char **argv)
{
	int sd, ret, fd;
	char buf[128];
	
	daemon(0, 0);

	ERRP((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1, "socket", goto ERR1);

	struct sockaddr_in src, from;// man 7 ip
	src.sin_family = AF_INET;
	src.sin_port = htons(9999);
	src.sin_addr.s_addr = INADDR_ANY;

	ERRP((ret = bind(sd, (struct sockaddr *)&src, sizeof(src))) == -1, "bind", goto ERR2);
	
	ERRP(listen(sd, 20) == -1, "listen", goto ERR3);

	int len = sizeof(from);
	while(1)
	{
		ERRP((fd = accept(sd, (struct sockaddr *)&from, &len)) == -1, "accept", goto ERR3);
		if (fork() == 0)
		{
			if (check_passwd(fd))//如果密码错误，一直循环
			{
				goto loop;
			}

		loop:
			exec_cmd(fd);

			close(fd);
			close(sd);
			exit(0);
		}
	}
	wait(NULL);
	close(sd);
	close(fd);
	return 0;
ERR3:
	memcpy(&src, src.sin_zero, sizeof(src.sin_zero));
ERR2:
	close(sd);
ERR1:
	return -1;
}
