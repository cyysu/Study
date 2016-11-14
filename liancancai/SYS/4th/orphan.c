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

//创建孤儿进程 和 僵尸 进程
int main(int argc, char **argv)
{
	int ret;

	ret = fork();

	//孤儿进程
	#if 1
	if (0 == ret)
	{
		sleep(1);

		printf("son, pid = %d, ppid = %d\n", getpid(), getppid());

		while(1)
		{
			sleep(1);
		}
	}
	else
	{
		printf("father, pid = %d\n", getpid());
		exit(0);
	}
	#else
	//僵尸进程
	if (0 == ret)
	{
		printf("child, pid = %d\n", getpid());

		exit(0);
	}
	else
	{
		sleep(1);

		printf("parents, pid = %d\n", getpid());

		while(1)
		{
		}
	}

	#endif

	return 0;
}
