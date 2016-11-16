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

int main(int argc, char **argv)
{
	// 12
	struct sockaddr_in buf;

	printf("sizeof(struct sockaddr_in) = %d\n", sizeof(struct sockaddr_in));

	printf("sizeof(buf.sin_family) = %d\n", sizeof(buf.sin_family));
	printf("sizeof(buf.sin_port) = %d\n", sizeof(buf.sin_port));
	printf("sizeof(buf.sin_addr) = %d\n", sizeof(buf.sin_addr));

	printf("sizeof(buf.sin_zero) = %d\n", sizeof(buf.sin_zero));
	printf("buf.sin_zero = %s\n", buf.sin_zero);

	memcpy(&buf, buf.sin_zero, 8);
	return 0;
}
