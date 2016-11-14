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

void hello(int sig)
{
	printf("\033[31mhello\033[0m\n");

}

int main(int argc, char **argv)
{
	int ret;
	int fd[2];
	char buf[128] = "123";

	printf("main start...\n");

	signal(SIGPIPE, hello);//向没有人读的fd写会产生　错误

	ret = pipe(fd);
	ERRP(-1 == ret, pipe, goto ERR1);

	printf("fd[WRITE] = %d\n", fd[WRITE]);
	printf("fd[READ] = %d\n", fd[READ]);

	ret = fork();
	ERRP(-1 == ret, fork, goto ERR1);

	if (0 == ret)//child
	{
		sleep(1);

		close(fd[READ]);

		ret = write(fd[WRITE], "123", 3);//因为没有进程去读这个　fd所以写会失败
		// printf("ret = %d\n", ret);
		ERRP(-1 == ret, write, goto ERR1);
		
		close(fd[WRITE]);
		exit(0);
	}

	close(fd[WRITE]);
	close(fd[READ]);

	wait(NULL);

	printf("main end...\n");

	return 0;
ERR1:
	return -1;
}
