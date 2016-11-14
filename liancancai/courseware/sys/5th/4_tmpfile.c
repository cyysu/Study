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
	int i;
	char buf[] = "cls_XXXXXX";
	char *p = NULL;
	int fd;

	fd = mkstemp(buf);
	if (fd == -1)
	{
		printf("mkdir failed!\n");
		return -1;
	}
	printf("buf = %s\n", buf);

	write(fd, "hello", 5);
	/*printf("p = %s\n", p);*/
	printf("fd = %d\n", fd);
	close(fd);
	unlink(buf);
	return 0;
}
