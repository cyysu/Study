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

int num = 111;

int main(int argc, char **argv)
{
	int ret;

	printf("main | num = %d, pid = %d\n", num, getpid());

	ret = fork();

	wait(NULL);
	
	if (0 == ret)
	{
		printf("child | num = %d, pid = %d\n", num, getpid());
		int num = 222;
		printf("child | num = %d, pid = %d\n", num, getpid());
	}
	else
	{
		printf("parents | num = %d, pid = %d\n", num, getpid());
		int num = 333;
		printf("parents | num = %d, pid = %d\n", num, getpid());
	}

	return 0;
}
