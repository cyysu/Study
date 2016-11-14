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

int main(int argc, char **argv)
{

	//孤儿进程
	#if 0
	if (!fork())
	{
		while(1)
			sleep(1);
	}
	#else
	//僵尸进程
	if (fork())
	{
		while(1)
			sleep(1);
	}
	else
	{
		printf("child!\n");
	}

	#endif




	return 0;
}
