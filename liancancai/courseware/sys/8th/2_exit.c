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

void *func(void *data)
{
	*(int *)data = 4321;

	printf("pth = %u pid = %d\n", pthread_self(), getpid());

	pthread_exit(data);
}
int main(int argc, char **argv)
{
	int count = 1234;
	int *p = NULL;
	pthread_t pth;

	pthread_create(&pth, NULL, func, &count);

	printf("main : pth = %u\n", pth);
	pthread_join(pth, (void **)&p);
	/*p = func(&count);*/

	printf("count = %d %p\n", count, &count);
	printf("*p = %d %p\n", *p, p);
	return 0;
}
