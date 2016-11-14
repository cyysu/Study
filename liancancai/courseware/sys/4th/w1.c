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

//实现tree命令

int lev = 0;

void mytree(char *path)
{
	DIR *dir = NULL;
	int i;
	struct dirent *dirp = NULL;
	//打开当前目录文件
	dir = opendir(path);
	if (dir == NULL)
	{
		return ;
	}
	//切换到工作目录中
	chdir(path);
	//获取目录的文件信息

	while((dirp = readdir(dir)) != NULL)
	{
		if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
		{
			continue;
		}
		if (dirp->d_type == 04)
		{
			for (i = 0; i < lev; i++)
			{
				printf("    ");
			}
			printf("|-- %s\n", dirp->d_name);
			lev++;
			mytree(dirp->d_name);
			lev--;
		}
		else
		{
			for (i = 0; i < lev; i++)
			{
				printf("    ");
			}
			printf("|-- %s\n", dirp->d_name);
		}
	}
	chdir("..");
	closedir(dir);
	
}
int main(int argc, char **argv)
{
	struct stat s;

	printf("%s\n", argv[1]);
	if (stat(argv[1], &s) == -1)
	{
		printf("stat failed!\n");
		return -1;
	}

	if (S_ISDIR(s.st_mode))
	{
		mytree(argv[1]);
	}


	return 0;
}
