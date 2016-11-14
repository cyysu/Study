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

#define INFORMATION   do{					\
		printf("file: %s\n", __FILE__);		\
		printf("func: %s\n", __func__);		\
		printf("line: %d\n", __LINE__);		\
}while(0)

#define ERRP(condition, string, ret) do{	\
		if(condition)						\
		{									\
			printf(#string" failed\n");		\
			INFORMATION;					\
			ret;							\
		}									\
}while(0)

int main(int argc, char **argv)
{
	DIR *dir = NULL;
	char *retp = NULL;
	int ret;
	char pwd[128] = {};
	// DIR *opendir(const char *name);

	 // char *getcwd(char *buf, size_t size);

	retp = getcwd(pwd, sizeof(pwd));//打印当前路径
	ERRP(NULL == retp, getcwd, goto ERR1);
	printf("%s\n", pwd);

	dir = opendir(argv[1]);//打开目录
	ERRP(NULL == dir, opendir, goto ERR1);

	ret = chdir(argv[1]);//切换到目的目录
	ERRP(-1 == ret, chdir, goto ERR2);

	retp = getcwd(pwd, sizeof(pwd));//打印当前路径
	ERRP(NULL == retp, getcwd, goto ERR2);
	printf("%s\n", pwd);

	ret = closedir(dir);
	ERRP(-1 == ret, closedir, goto ERR1);

	return 0;
ERR2:
	closedir(dir);
ERR1:
 	return -1;
}
