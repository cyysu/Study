#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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
	int ret;
	int fd;

	umask(0);
	if(strcmp(argv[1], "creat") == 0)
	{
		fd = creat(argv[2], 0755);
		ERRP(-1 == fd, creat argv[2], goto ERR1);
		printf("creat done !\n");
	}

	// remove 可以删除空目录
	if(strcmp(argv[1], "remove") == 0)
	{
		ret = remove(argv[2]);
		ERRP(-1 == ret, remove argv[2], goto ERR1);
		printf("remove done !\n");
	}

	if(strcmp(argv[1], "link") == 0)
	{
		ret = link(argv[2], argv[3]);
		ERRP(-1 == ret, link, goto ERR1);
		printf("link done !\n");
	}

	if(strcmp(argv[1], "symlink") == 0)
	{
		ret = symlink(argv[2], argv[3]);
		ERRP(-1 == ret, symlink, goto ERR1);
		printf("symlink done !\n");
	}

	//只能删除文件
	if(strcmp(argv[1], "unlink") == 0)
	{
		ret = unlink(argv[2]);
		ERRP(-1 == ret, unlink, goto ERR1);
		printf("unlink done !\n");
	}

	// umask(0);
	//减去了umask
	if(strcmp(argv[1], "chmod") == 0)
	{
		ret = chmod(argv[2], 00777);
		ERRP(-1 == ret, chmod, goto ERR1);
		printf("chmod done !\n");
	}

	if(strcmp(argv[1], "chown") == 0)
	{
		ret = chown(argv[2], 1001, 1001);
		ERRP(-1 == ret, chown, goto ERR1);
		printf("chown done !\n");
	}

	// int mkdir(const char *pathname, mode_t mode);
	if(strcmp(argv[1], "mkdir") == 0)
	{
		ret = mkdir(argv[2], 00755);
		ERRP(-1 == ret, mkdir, goto ERR1);
		printf("mkdir done !\n");
	}

	if(strcmp(argv[1], "rmdir") == 0)
	{
		ret = rmdir(argv[2]);
		ERRP(-1 == ret, rmdir, goto ERR1);
		printf("rmdir done !\n");
	}
	
	return 0;
ERR1:
	return -1;
}
