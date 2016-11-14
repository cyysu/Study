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

typedef void (*sighandler_t)(int);

void hello(int sig)
{
	printf("hello! : %d\n", time(NULL));
}
int main(int argc, char **argv)
{
	int ret;
	struct itimerval it;

	//处理信号
	/*signal(SIGALRM, hello);*/
	signal(SIGVTALRM, hello);
	//设置时间 循环时间
	it.it_interval.tv_sec = 0;
	it.it_interval.tv_usec = 1000;

	//current 第一次执行时间
	it.it_value.tv_sec =0;
	it.it_value.tv_usec = 1000;

	/*ret = setitimer(ITIMER_REAL, &it, NULL);*/
	ret = setitimer(ITIMER_VIRTUAL, &it, NULL);
	if (ret == -1)
	{
		printf("setitimer failed!\n");
		return -1;
	}

	/*getchar();*/
	while(1)
		;
	return 0;
}
