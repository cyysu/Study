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

#define NUM 10

/*
 *pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;//初始化锁
 *pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;//初始化锁
 */

pthread_mutex_t mutex;

void *do_work(void *data)
{
	char buf[128];
	int count = 0, i;
	int fd = *(int *)data;

	//加锁
	pthread_mutex_lock(&mutex);
	/*pthread_mutex_lock(&mutex1);*/
	while(1)
	{
		if (count >= 100)
		{
			pthread_mutex_unlock(&mutex);
			pthread_exit(NULL);
		}
		snprintf(buf, sizeof(buf), "pthread_id : %lu count : %d\n", pthread_self(), count++);
		for (i = 0; i < strlen(buf); i++)
		{
			write(fd, &buf[i], 1);
		}

	}
	//解锁
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}
int main(int argc, char **argv)
{
	int i;
	int fd;
	pthread_t pth[NUM];

	/*printf("PTHREAD_MUTEX_INITIALIZER = %d\n", PTHREAD_MUTEX_INITIALIZER);*/
	//初始化
	pthread_mutex_init(&mutex, NULL);
	fd = open("./test", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		return -1;
	}

	for (i = 0; i < NUM; i++)
	{
		pthread_create(&pth[i], NULL, do_work, &fd);
	}

	for (i = 0; i < NUM; i++)
	{
		pthread_join(pth[i], NULL);
	}
	//锁的销毁
	pthread_mutex_destroy(&mutex);
	return 0;
}
