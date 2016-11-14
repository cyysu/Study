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

int count = 0;
//求栈的大小
void stack(void)
{
	char buf[1024];
	printf("count = %d\n", count++);
	stack();
}

int main(int argc, char **argv)
{
	//RLIMIT_STACK

	int ret;
	struct rlimit r;

	ret = getrlimit(RLIMIT_STACK, &r);
	if (ret == -1)
	{
		return -1;
	}

	//设定堆栈的软限额为5M
	r.rlim_cur = 1024 * 1024;

	setrlimit(RLIMIT_STACK, &r);

	stack();
	return 0;
}
