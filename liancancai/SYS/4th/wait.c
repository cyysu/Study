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

int main(int argc, char **argv)
{
	int ret;

	if (fork())
	{
		int status;
		printf("parents| ppid = %d, pid = %d\n", getppid(), getpid());
		wait(&status);
		printf("status = %d\n", status);
	}
	else
	{
		sleep(1);
		printf("child | ppid = %d, pid = %d \n", getppid(), getpid());
		exit(10);
	}
	return 0;
}
