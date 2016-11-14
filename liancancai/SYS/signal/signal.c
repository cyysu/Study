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

typedef void (*sighandler_t)(int);

void hello(int a)
{
	printf("hello\n");
	printf("%d\n", a);
}

int main(int argc, char **argv)
{
	// typedef void (*sighandler_t)(int);

	// sighandler_t signal(int signum, sighandler_t handler);
	sighandler_t p = NULL;

	p = signal(2, SIG_IGN);

	while(1)
	{
		sleep(1);
	}

	return 0;
}
