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

	lstat(argv[1], &s);

	s.st_mode;
	//定义一个类型
	mode_t m = s.st_mode;
	
	//判断是否是普通文件-
	//第一种方式
	// if (S_ISREG(m))
	// {
	// 	printf("-");
	// }
	//第二中方式
	//if ((m & S_IFREG) == 0100000)

   // S_IFSOCK   0140000   socket
   // S_IFLNK    0120000   symbolic link
   // S_IFREG    0100000   regular file
   // S_IFBLK    0060000   block device
   // S_IFDIR    0040000   directory
   // S_IFCHR    0020000   character device
	// S_IFIFO
	// if (S_ISDIR(m))
	// {
	// 	printf("d");
	// }
	// if (S_ISCHR(m))
	// {
	// 	printf("c");
	// }
	// if (S_ISBLK(m))
	// {
	// 	printf("b");
	// }
	// if (S_ISFIFO(m))
	// {
	// 	printf("p");
	// }
	// if (S_ISLNK(m))
	// {
	// 	printf("l");
	// }
	// if (S_ISSOCK(m))
	// {
	// 	printf("s");
	// }

	//s
	// printf("m = %#o\n", m);
	//s
	if ( (m & S_IFSOCK) == S_IFSOCK)
	{
		printf("s");
	}

	//l

	else if ( (m & S_IFLNK) == S_IFLNK)
	{
		printf("l");
	}

	//-
	else if ( (m & S_IFREG) == S_IFREG)
	{
		printf("-");
	}

	//b
	else if ( (m & S_IFBLK) == S_IFBLK)
	{
		printf("b");
	}

	//d
	else if ( (m & S_IFDIR) == S_IFDIR)
	{
		printf("d");
	}

	//c
	else if ( (m & S_IFCHR) == S_IFCHR)
	{
		printf("c");
		// printf("do c\n");
	}

	//p
	else if ( (m & S_IFIFO ) == S_IFIFO )
	{
		printf("p");
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
	//x 
	if ((m & S_IXUSR) == S_IXUSR)
	{
		printf("x");
	}
	else
	{
		printf("-");
	}

	//属组
	//r
	if ((m & S_IRGRP) == S_IRGRP)
	{
		printf("r");
	}
	else
	{
		printf("-");
	}
	//w
	if ((m & S_IWGRP) == S_IWGRP)
	{
		printf("w");
	}
	else
	{
		printf("-");
	}
	//x 
	if ((m & S_IXGRP) == S_IXGRP)
	{
		printf("x");
	}
	else
	{
		printf("-");
	}
	//其他用户
	//r
	if ((m & S_IRGRP) == S_IRGRP)
	{
		printf("r");
	}
	else
	{
		printf("-");
	}
	//w
	if ((m & S_IWGRP) == S_IWGRP)
	{
		printf("w");
	}
	else
	{
		printf("-");
	}
	//x 
	if ((m & S_IXGRP) == S_IXGRP)
	{
		printf("x");
	}
	else
	{
		printf("-");
	}
	printf("\n");

	return 0;
}
