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
	int i;
	int ret;

	for (i = 0; i < 10; i++)
	{
		ret = fork();
		if (ret == 0)
		{
			printf("pid = %d : hello!\n", getpid());
			exit(0);
		}
	}
	return 0;
}
