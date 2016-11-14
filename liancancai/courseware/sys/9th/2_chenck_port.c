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


#define PORT 123456

//客户端
int main(int argc, char **argv)
{
	int i;
	int sd;
	int ret;

	struct sockaddr_in dest;
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = inet_addr("10.1.1.72");

	for (i = 0; i < 65535; i++)
	{
		sd = socket(PF_INET, SOCK_STREAM, 0);
		if (sd == -1)
		{
			printf("socket failed!\n");
			return -1;
		}

		dest.sin_port = htons(i);

		ret = connect(sd, (struct sockaddr *)&dest, sizeof(dest));
		if (ret != -1)
		{
			printf("%d ", i);
		}
		close(sd);
	}
	printf("\n");
	return 0;
}
