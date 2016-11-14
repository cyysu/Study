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

#define MAX 6000
#define MIN 3000
#define NUM 10
#define STEP ((MAX - MIN) / NUM)

//统计素数
void *counter(void *data)
{
	int i, j;
	int *p = NULL;//不能返回局部地址，　创建指针p并申请空间，用来做返回值
	int count = 0;

	p = (int *)malloc(sizeof(int));
	ERRP(NULL ==p, malloc, goto ERR1);

	printf("\033[31m%d ~ %d\033[0m\n", *(int *)data, *(int *)data + STEP);

	for (i = *(int *)data; i < *(int *)data + STEP; i ++)
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
			count ++;
			printf("%d\n", i);
		}
	}

	printf("\033[32mcount = %d\033[0m\n", count);
	printf("\n\n");

	memcpy(p, &count, sizeof(int));

	pthread_exit(p);//返回指针p
ERR1:
	pthread_exit(NULL);
}

int main(int argc, char **argv)
{
	int i, j;
	int ret;
	pthread_t pthread;
	int *p = NULL;
	int count = 0;

	for (i = 0; i < NUM; i++)
	{
		j = MIN + i * STEP;

		pthread_create(&pthread, NULL, counter, &j);//子函数线程

		pthread_join(pthread,(void **)&p);//主函数线程
		
		count += *p;
	}

	printf("count = %d\n", count);

	return 0;
}
