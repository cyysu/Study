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

int count = 1234;//全局 DS
int main(int argc, char **argv)
{
	int ret;

	ret = fork();
	if (ret == 0)
	{
		count = 54321;
		int num;
		printf("num = %p\n", &num);
		printf("child : count = %d\n", count);
	}
	else
	{
		sleep(1);
		printf("parent : count = %d\n", count);
	}
	return 0;
}
