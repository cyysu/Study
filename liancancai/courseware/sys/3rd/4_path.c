#define _GNU_SOURCE
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
	char *p = NULL;
	char buf[10];

	//获取当前的工作目录
	p = getcwd(NULL,0);
	/*p = getwd(buf);*/
	if (p == NULL)
	{
		printf("getcwd failed!\n");
		return -1;
	}
	printf("p = %s : %p\n", p, p);
	free(p);
	p = get_current_dir_name();
	printf("p = %s\n", p);

	chdir("/test");
	printf("path = %s\n", get_current_dir_name());
	creat(argv[1], 0666);
	/*printf("buf = %s : %p\n", buf, buf);*/


	return 0;
}
