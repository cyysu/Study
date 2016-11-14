#define _XOPEN_SOURCE
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


int main(int argc, char **argv)
{
	struct spwd *sp = NULL;
	char *passwd = NULL;

	//输入用户名，获取用户密码所有文件信息
	sp = getspnam(argv[1]);
	if (sp == NULL)
	{
		printf("getspnam failed!\n");
		return -1;
	}
	printf("username : %s | userpasswd : %s\n", sp->sp_namp, sp->sp_pwdp);

	//用户输入一个关键字获取md5加密程序
	/*passwd = crypt(argv[2], "$1$ai6ONfdG$");*/
	passwd = crypt(argv[2], sp->sp_pwdp);

	printf("passwd = %s\n", passwd);

	return 0;
}
