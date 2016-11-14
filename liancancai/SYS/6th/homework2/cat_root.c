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

#define WRITE 1
#define READ 0

int main(int argc, char **argv)
{
	int ret;
	int fd[2];
	char buf[128] = {};

	printf("main start...\n");

	ret = pipe(fd);
	ERRP(-1 == ret, pipe, goto ERR1);
	
	ret = fork();
	ERRP(-1 == ret, fork, goto ERR1);
	
	if (0 == ret)//child 
	{
		
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);

		execlp("cat", "cat", "/etc/passwd", NULL);

	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);

		execlp("grep", "grep", "root", NULL);
	}

ERR1:
	return -1;
}

