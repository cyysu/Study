#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

//全局报错变量
//声明一个外部变量
extern errno;

int main(int argc, char **argv)
{
	FILE *fp = NULL;
	int *p = NULL;

    /*
	 *p = (int *)malloc(sizeof(int));
	 *p = NULL;
	 *if (p == NULL)
	 *{
	 *    perror("malloc");
	 *    return -1;
	 *}
     */
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		/*printf("fopen failed!\n");*/
		printf("errno = %d\n", errno);//打印错误代码
		printf("strerror = %s\n", strerror(errno));//打印错误信息
		perror("fopen");//打印报错信息
		return -1;
	}
	return 0;
}
