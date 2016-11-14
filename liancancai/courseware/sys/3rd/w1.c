#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char **argv)
{
	char path[128];
	struct stat s;
	int ret;
	char type[] = " pc d b - l s";
	char *mode[] = {"---", "--x", "-w-", "-wx", "r--", "r-x", "rw-", "rwx"};


	printf("please input path : ");
	fgets(path, sizeof(path), stdin);
	if (path[strlen(path) - 1] == '\n')
		path[strlen(path) - 1] = '\0';

	ret = lstat(path, &s);
	if (ret == -1)
	{
		printf("stat failed!\n");
		return -1;
	}
	
	//获取文件类型和权限
	printf("%c%s%s%s", type[(s.st_mode & S_IFMT) >> 12], mode[(s.st_mode & S_IRWXU) >> 6], mode[(s.st_mode & S_IRWXG) >> 3], mode[s.st_mode & S_IRWXO]);

	//获取硬链接数
	printf(" %d", s.st_nlink);

	//获取文件属主
	struct passwd * pwd = NULL;
	pwd = getpwuid(s.st_uid);
	if (pwd == NULL)
	{
		printf(" %d", s.st_uid);
	}
	else
	{
		printf(" %s", pwd->pw_name);
	}
	//获取文件属组
	struct group *grp = NULL;

	grp = getgrgid(s.st_gid);
	if (NULL == grp)
	{
		printf(" %d", s.st_gid);
	}
	else
	{
		printf(" %s", grp->gr_name);
	}
	//获取文件大小
	int count= 0;
	char total[] = " KMGT";
	while(s.st_size >= 1024)
	{
		s.st_size /= 1024;
		count++;
	}
	printf(" %d%c", s.st_size, total[count]);

	printf("\n");
	return 0;
}
