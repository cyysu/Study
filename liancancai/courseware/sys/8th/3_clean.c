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

void hello(void *data)
{
	printf("%d\n", (int *)data);
}

void *func(void *data)
{
	int *p 
	pthread_cleanup_push(hello, (void *)11111);
	pthread_cleanup_push(hello, (void *)22222);
	pthread_cleanup_push(hello, (void *)33333);
	pthread_cleanup_push(hello, (void *)44444);
	pthread_cleanup_push(hello, (void *)55555);


	
}
int main(int argc, char **argv)
{
	printf("main stat!\n");

	pthread_create(&pth, NULL, func, NULL)

	/*pthread_cleanup_pop(0);*/
	
	printf("hello!\n");
	printf("main end!\n");

	pthread_cleanup_pop(0);
	pthread_cleanup_pop(1);
	pthread_cleanup_pop(1);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(1);

	return 0;
}
