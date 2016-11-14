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

int main(int argc, char **argv)
{
	int fd;
	int ret;
	int i;
   // int open(const char *pathname, int flags);
	fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND);
	ret = fork();

	if(0 == ret)
	{
		for(i = 0; i < 60000; i ++)
		{
			write(fd, "c", 1);
		}
		close(fd);
	}
	else
	{
		for(i = 0; i < 60000	; i ++)
		{
			write(fd, "p", 1);
		}
		close(fd);
	}

	return 0;
}
