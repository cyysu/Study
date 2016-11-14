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
	int ret;
	int num = 12345;

	ret = fork();

	if (ret == 0)
	{
		printf("child! num = %d %p\n", num, &num);
		int num = 1122;//运行时段
		printf("child! num = %d %p\n", num, &num);
	}
	else
	{
		num = 54321;
		int num;//父进程运行时段。
		printf("parent! num = %d %p\n", num, &num);
	}
	return 0;
}
