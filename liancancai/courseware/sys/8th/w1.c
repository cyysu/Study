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
#include <share.h>

#define NUM 10
#define MIN 3000
#define MAX 6000
#define STEP (MAX - MIN)/NUM


struct op_t{
	int min;
	int max;
};

int count = 0;
//创建10线程

void *prime(void *data)
{
	int i, j;
	int min = *(int *)data;
	int max = min + STEP;
	/*int count = 0;*/
	int *p = NULL;

	p = (int *)malloc(sizeof(int));
	if (p == NULL)
	{
		pthread_exit(NULL);
	}
	/*printf("pth : %lu | min = %d\n", pthread_self(), min);*/
	/*printf("pth : %lu pid : %d\n", pthread_self(), getpid());*/

	for (i = min; i < max; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			count++;
		}
	}
	*p = count;
	/*printf("%d ~ %d : count = %d\n", min, max, count);*/
	pthread_exit(p);
}
int main(int argc, char **argv)
{
	int i;
	pthread_t pth[NUM];//保存线程号
	int arr[NUM];//保存变量值
	int tmp;
	int *p = NULL;
	struct op_t op;
	/*int count = 0;*/

	printf("pid : %d\n", getpid());
	for (i = 0; i < NUM; i++)
	{
		/*tmp = MIN + i * STEP;*/
		/*printf("tmp = %d\n", tmp);*/
		arr[i] = MIN + i * STEP;
		/*pthread_create(pth + i, NULL, prime, (void *)(MIN + i * STEP));*/
		pthread_create(pth + i, NULL, prime, &arr[i]);
		/*sleep(1);*/
	}

	for (i = 0; i < NUM; i++)
	{
		pthread_join(pth[i], (void **)&p);
		/*count += *p;*/
	}
	printf("count = %d\n", count);
	return 0;
}
