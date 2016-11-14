#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	struct stat s;
	char *buf[] = {"---", "--x", "-w-", "-wx", "r--", "r-x", "rw-", "rwx"};


	lstat(argv[1], &s);
	mode_t m = s.st_mode;

	printf("mode : %s\n", buf[(m & S_IRWXU) >> 6]);
	s.st_mode;
	//定义一个类型
	
	//判断是否是普通文件-
	//第一种方式
	if (S_ISREG(m))
	{
		putchar('-');
	}
	//第二中方式
	//if ((m & S_IFREG) == 0100000)
	if ((m & S_IFREG) == S_IFREG)
	{
		putchar('-');
	}

	if (S_ISDIR(m))
	{
		putchar('d');
	}
	if (S_ISCHR(m))
	{
		putchar('c');
	}
	if (S_ISBLK(m))
	{
		putchar('b');
	}
	if (S_ISFIFO(m))
	{
		putchar('p');
	}
	if (S_ISLNK(m))
	{
		putchar('l');
	}
	if (S_ISSOCK(m))
	{
		putchar('s');
	}

	//获取文件权限
	//属主
	//r
	if ((m & S_IRUSR) == S_IRUSR)
	{
		printf("r");
	}
	else
	{
		printf("-");
	}
	//w
	if ((m & S_IWUSR) == S_IWUSR)
	{
		printf("w");
	}
	else
	{
		printf("-");
	}
	//x -> own
	if ((m & S_IXUSR) == S_IXUSR)
	{
		printf("x");
	}
	else
	{
		printf("-");
	}

	//属组
	//其他用户
	printf("\n");

	return 0;
}
