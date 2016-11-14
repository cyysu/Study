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

#define READ 0
#define WRITE 1

int main(int argc, char **argv)
{
	int ret;
	int fd[2];
	int count = 0;
	char buf[1024];

	ret = pipe(fd);
	ERRP(-1 == ret, pipe, goto ERR1); 

	printf("fd[READ] = %d\n", fd[READ]);
	printf("fd[WRITE] = %d\n", fd[WRITE]);

	while(1)
	{
		count ++;
		write(fd[WRITE], buf, sizeof(buf));
		printf("%d\n", count);
	}

	close(fd[WRITE]);
	close(fd[READ]);

	return 0;
ERR1:
	return -1;
}
