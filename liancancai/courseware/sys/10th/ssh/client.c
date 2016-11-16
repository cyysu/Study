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

int main(int argc, char **argv)
{
	int sd, ret;
	char buf[128];

	ERRP((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1, "socket", goto ERR1);

	struct sockaddr_in dest;
	dest.sin_family = AF_INET;
	dest.sin_port = htons(9999);
	dest.sin_addr.s_addr = inet_addr(argv[1]);
	ERRP((ret = connect(sd, (struct sockaddr *)&dest, sizeof(dest))) == -1, "conect", goto ERR2);


	while(1)
	{
		fprintf(stderr, "root@%s's password: ", argv[1]);
		GETLINES("", buf, sizeof(buf));

		write(sd, buf, strlen(buf) + 1);//包括尾零

		read(sd, buf, sizeof(buf));
		if (!strcmp(buf, "yes"))
		{
			break;
		}
	}

	memset(buf, 0, sizeof(buf));
	//Last login: Mon Nov 14 16:36:13 2016 from aa.bb.com
	read(sd, buf, sizeof(buf));
	printf("%s\n", buf);
	fflush(NULL);

	while(1)
	{
		fprintf(stderr, "[root@www ~]# ");
		GETLINES("", buf, sizeof(buf));
		write(sd, buf, strlen(buf) + 1);
		if (strcmp(buf, "exit") == 0)
		{
			break;
		}

		read(sd, buf, sizeof(buf));
		printf("%s", buf);
		fflush(NULL);

	}

	close(sd);
	return 0;
ERR2:
	close(sd);
ERR1:
	return -1;
}
