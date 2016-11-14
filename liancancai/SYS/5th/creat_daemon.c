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

	ret = fork();
	ERRP(-1 == ret, fork, goto ERR1);

	if (0 != ret)//parents
	{
		exit(0);	
	}
	else//child
	{
		int i;
		int count;

		struct rlimit rlim;

		ret = getrlimit(RLIMIT_NOFILE, &rlim);
		if (-1 == ret)
		{
			printf("getrlimit failed\n");
			exit(0);
		}

		count = rlim.rlim_cur;

		printf("count = %d\n", count);

		ret = setsid();
		if (-1 == ret)
		{
			exit(0);
		}


		chdir("/");

		umask(0);

		for (i = 0; i < count; i ++)
		{
			close(i);
		}

		while(1)
		{
			sleep(2);
		}

	}

	return 0;
ERR1:
	return -1;
}
