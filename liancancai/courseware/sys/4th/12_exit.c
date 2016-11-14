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
#include <time.h>
#include <dirent.h>
#include <glob.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	
	if (fork() == 0)
	{
		printf("child! : pid = %d\n", getpid());
		/*return 123;*/
		exit(-1);// 0 - 255
		/*_exit(0);*/
		/*abort();*/
		kill(getpid(), 9);
	}

	/*sleep(1);*/
	int status;
	wait(&status);
	printf("WIFEXITED(status) = %d\n", WIFEXITED(status));
	if (WIFEXITED(status))
	{
		printf("WEXITSTATUS(status) = %d\n", WEXITSTATUS(status));
	}
	printf("WIFSIGNALED(status) = %d\n", WIFSIGNALED(status));
	if (WIFSIGNALED(status))
	{
		printf("WTERMSIG(status) = %d\n", WTERMSIG(status));
	}
	/*printf("status = %d\n", status);*/
	printf("parent!\n");

	return 0;
}
