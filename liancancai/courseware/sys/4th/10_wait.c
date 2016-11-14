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

	if (!fork())
	{
		sleep(1);
		printf("child! : pid = %d\n", getpid());

		return 10;
	}
	else
	{
		int stat;
		printf("parent! : pid = %d\n", getpid());
		wait(&stat);
		printf("stat = %d\n", stat);
	}
	return 0;
}
