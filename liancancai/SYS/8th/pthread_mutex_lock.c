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
#include <crypt.h>
#include <time.h>
#include <dirent.h>
#include <glob.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <pthread.h>



#define INFORMATION   do{					\
		printf("file: %s\n", __FILE__);		\
		printf("func: %s\n", __func__);		\
		printf("line: %d\n", __LINE__);		\
}while(0)

#define ERRP(condition, string, ret) do{	\
		if(condition)						\
		{									\
			printf(#string" failed\n");		\
			INFORMATION;					\
			ret;							\
		}									\
}while(0)

#define NUM 10

// pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex;

void *do_work(void *data)
{
	int fd = *(int *)data;
	char buf[128] = {};
	int count  = 1;
	int ret, i;
	int buf_size = 0;

	pthread_mutex_lock(&mutex);
	// printf("do_work: fd = %d\n", fd);

	while(1)
	{
		snprintf(buf, sizeof(buf), "pthread_id = %ld, count = %d\n", pthread_self(), count++);

		buf_size = strlen(buf);
		for (i = 0; i < buf_size; i ++)
		{
			write(fd, &buf[i], 1);
		}

		// write(fd, buf, strlen(buf));//这里要用strlen(buf), 不能使用sizeof(buf)

		if (count > 100)
		{
			break;
		}
	}

	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);

ERR1:
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

int main(int argc, char **argv)
{
	int fd;
	pthread_t pthread[10];
	int ret;
	int i;

	fd = open("./test", O_RDWR | O_CREAT | O_TRUNC, 0666);
	ERRP(-1 == fd, open, goto ERR1);

	pthread_mutex_init(&mutex, NULL);
	// printf("main : fd = %d\n", fd);

	for (i = 0; i < NUM; i ++)
	{	
		ret = pthread_create(&pthread[i], NULL, do_work, &fd);
		ERRP(ret != 0, pthread_create, goto ERR1);

	}

	for (i = 0; i < NUM; i++)
	{
		pthread_join(pthread[i], NULL);
	}

	close(fd);

	return 0;
ERR1:
	return -1;
}
