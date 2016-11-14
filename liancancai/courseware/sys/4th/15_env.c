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

extern char **environ;

//查看当前进程环境变量
/*int main(int argc, char **argv)*/
int main(int argc, char **argv, char **env)
{
	int i;
	//打印用户传递参数
    /*
	 *for (i = 0; i < argc; i++)
	 *{
	 *    printf("argv[%d] = %s\n", i, argv[i]);
	 *}
     */
	//打印环境变量
    /*
	 *i = 0;
	 *while(environ[i] != NULL)
	 *{
	 *    printf("%s\n", environ[i]);
	 *    i++;
	 *}
     */

	//获取环境变量
	int ret;
	printf("hostname = %s\n", getenv("HOSTNAME"));
	setenv("HOSTNAME", "www.uplooking.com", 0);

    /*
	 *ret = putenv("HOSTNAME=www.baidu.com");
	 *if (ret != 0)
	 *{
	 *    printf("putenv failed!\n");
	 *    return -1;
	 *}
     */

	/*unsetenv("HOSTNAME");*/
	printf("hostname = %s\n", getenv("HOSTNAME"));

	setenv("aaa", "bbbb", 1);
	printf("aaa = %s\n", getenv("aaa"));
	clearenv();
	i = 0;
	while(environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}

	return 0;
}
