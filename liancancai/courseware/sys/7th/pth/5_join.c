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
	int *p = NULL;

	// &p 局部变量
	//p 动态内存
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
	unsigned long int pth;	
	int **p = NULL;

	// &p p *p
	pthread_create(&pth, NULL, func, NULL);
	p = (int **)malloc(sizeof(int *));

	pthread_join(pth, (void **)p);

	printf("**p = %d\n", **p);// &p

	free(*p);
	free(p);


	return 0;
}
