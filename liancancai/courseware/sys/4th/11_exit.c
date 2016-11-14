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
#include <pthread.h>

int main(int argc, char **argv)
{
	//一个程序至少包含一个进程。 而一个进程至少包含一个线程。
	printf("pid = %d\n", getpid());//获取进程号
	printf("pthread = %lu\n", pthread_self());//获取线程号
	//gcc file.c -lpthread //表示连接线程动态库

	exit(123);
	pthread_exit(NULL);//线程退出
	printf("hello!\n");
	return 11;//从main函数退出 0 ~ 255
}
