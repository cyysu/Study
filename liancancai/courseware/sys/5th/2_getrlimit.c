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
#include <sys/time.h>
#include <sys/resource.h>

int main(int argc, char **argv)
{
	int ret;
	struct rlimit r;

	ret = getrlimit(RLIMIT_NOFILE, &r);
	if (ret == -1)
	{
		printf("getrlimit failed!\n");
		return -1;
	}

	printf("rlim_cur = %d\n", r.rlim_cur);
	printf("rlim_max = %d\n", r.rlim_max);

	/*r.rlim_cur = 2000;*/
	/*r.rlim_max = 1000;*/
	
	setrlimit(RLIMIT_NOFILE, &r);
	int fd, i;
	for (i = 0; i < 1024; i++)
	{
		fd = open("./test", O_RDONLY);
		if (fd == -1)
		{
			break;
		}
		printf("fd = %d\n", fd);
	}
	getrlimit(RLIMIT_NOFILE, &r);
	printf("rlim_cur = %d\n", r.rlim_cur);
	printf("rlim_max = %d\n", r.rlim_max);


	return 0;
}
