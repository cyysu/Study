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

//函数指针
typedef void (*sighandler_t)(int);

void hello(int sig)
{
	printf("hello! sig = %d\n", sig);
}

int main(int argc, char **argv)
{
	
	sighandler_t p = NULL;

	/*p = signal(2, hello);*/
	p = signal(2, SIG_IGN);
	/*p = signal(2, SIG_DFL);*/
	/*p = signal(2, hello);*/
	if (p == SIG_ERR)
	{
		printf("signal failed!\n");
		return -1;
	}
	printf("p = %p\n", p);
	printf("hello = %p\n", hello);

	while(1)
	{
		sleep(3);
	}
	return 0;
}
