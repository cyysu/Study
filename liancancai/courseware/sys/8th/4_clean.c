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

void free_add(void *p)
{
	printf("hello!\n");
	free(p);
}
void * func(void *data)
{
	int *p = NULL;


	printf("pth = %u\n", pthread_self());
	p = (int *)malloc(sizeof(int));
	if (p == NULL)
	{
		pthread_exit(NULL);
	}
	*p = 1234;

	pthread_exit(p);
}

int main(int argc, char **argv)
{
	int i;	
	pthread_t pth[2];
	int *p = NULL;

	pthread_cleanup_push(free_add, (void *)p);
	for (i = 0; i < 2; i++)
	{
		pthread_create(pth + i, NULL, func, NULL);
	}

	for (i = 0; i < 2; i++)
	{
		pthread_join(pth[i], (void **)&p);
	}
	pthread_cleanup_pop(1);
	/*pthread_cleanup_pop(1);*/
	return 0;
}
