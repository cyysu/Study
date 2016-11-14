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
	printf("hello!\n");

	printf("pid = %d\n", getpid());
	printf("ppid = %d\n", getppid());
	while(1)
		sleep(1);
	return 0;
}
