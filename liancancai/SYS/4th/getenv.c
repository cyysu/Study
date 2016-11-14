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

extern char **environ;

int main(int argc, char **argv, char **env)
{
	int i = 0;

	/*while(environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}*/
	if (getenv(argv[1]) != NULL)
	{
		printf("%s\n", getenv(argv[1]));
	}
	else
	{
		printf("not find\n");
		return -1;
	}

	setenv(argv[1], "123", 1);

	printf("%s\n", getenv(argv[1]));
	
	return 0;
}
