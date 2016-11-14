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

int main(int argc, char **argv)
{
	int ret;
	char buf[128];

	/*printf("file = %s\n", argv[1]);*/
	struct stat s;

	lstat(argv[1], &s);

	if (S_ISLNK(s.st_mode))
	{
		ret = readlink(argv[1], buf, sizeof(buf));
		if (ret == -1)
		{
			printf("readlink failed!\n");
			return -1;
		}
		printf("%s -> %s", argv[1], buf);
	}
	else
	{
		printf("%s", argv[1]);
	}
	putchar(10);
	return 0;
}
