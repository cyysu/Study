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

int count = 12345;

void *hello(void *data)
{
	int count = 1122;
	printf("func : count = %d\n", count);
	count = 54321;
	//子函数线程
	printf("hello! pthread_self = %u pid = %d\n", pthread_self(), getpid());
	return NULL;
}
int main(int argc, char **argv)
{
	int ret;
	pthread_t pth;
	//创建一个线程
	
	ret = pthread_create(&pth, NULL, hello, NULL);
	if (ret != 0)
	{
		printf("pthread_create failed!\n");
		return -1;
	}

	sleep(1);
    /*
	 *printf("pth = %u\n", pth);
	 *printf("pth = %d\n", pth);
     */
	//主程序 主函数的线程
	printf("pthread_self = %lu pid = %d\n", pthread_self(), getpid());
	printf("main : count = %d\n", count);
	return 0;
}
