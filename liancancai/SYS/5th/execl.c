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

extern char **environ;

int main(int argc, char **argv)
{
	  // int execl(const char *path, const char *arg, ...);
   //     int execlp(const char *file, const char *arg, ...);
   //     int execle(const char *path, const char *arg,
   //                ..., char * const envp[]);
   //     int execv(const char *path, char *const argv[]);
   //     int execvp(const char *file, char *const argv[]);
   //     int execvpe(const char *file, char *const argv[],
   //                 char *const envp[]);
	int ret;

	printf("main start...\n");

	ret = fork();
	if (-1 == ret)
	{
		printf("fork failed\n");
		return -1;
	}

	if (ret == 0)//child
	{
		int ret;

		// ret = execl("/bin/ls", "-a", "-h", "-l", NULL);
		   // ret = execl("/bin/ls", "-ahl", NULL);//只会执行第一个参数,必须分开写
	   // ret = execlp("ls", "-a", "-l", "-h", NULL);//只用写命令名就可以了
	    ret = execle("/bin/ls", "-a", "-h", "-l", NULL, environ);
		if (-1 == ret)
		{
			printf("execl failed\n");
			exit(0);
		}

	}

	wait(NULL);

	printf("start end...\n");
	
	return 0;
}

