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

typedef void (*FUNC)(int);

void hello(int sig)
{
	alarm(1);
	printf("hello!\n");
}
int main(int argc, char **argv)
{
	int i = 0;
	FUNC p = NULL;

	p = signal(2, hello);
	p = signal(SIGALRM, hello);
	if (p == SIG_ERR)
	{
		printf("signal failed!\n");
		return -1;
	}

	alarm(5);

	/*while(1)*/
	for (i = 0; i < 5; i++)
		pause();
	return 0;
}
