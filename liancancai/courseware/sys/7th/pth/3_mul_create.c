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

#define MAX 10

void *func(void *data)
{
	printf("hello! : %u\n", pthread_self());
	/*return NULL;*/
}
int main(int argc, char **argv)
{
	int i;
	pthread_t pth[MAX];

	for (i = 0; i < 10; i++)
	{
		pthread_create(&pth[i], NULL, func, NULL);
	}

	sleep(1);
	return 0;
}
