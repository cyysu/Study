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
#include <sys/time.h>
#include <sys/resource.h>

extern environ;

int main(int argc, char **argv, char **env)
{
	int ret;
	char *ar[] = {"ls", "-l", "-i", "-h", "/tmp", NULL};
	char *p_ar[] = {"hello", "123", "456world", "test123", "tom", "4.567", NULL};
	char *p_env[] = {"root=tom", "hostname=www.uplooking.com", "abc=123", NULL};
	// ls
	//test -> ar env
	execve("./test", p_ar, p_env);

	printf("main : stat!\n");
	printf("hello!\n");
	/*ret = execl("ls", "ls", "-h", "-l",  "-i", "/ken", NULL);*/
	/*ret = execlp("/bin/ls", "ls", "-h", "-l",  "-i", "/ken", NULL);*/
	/*ret = execle("/bin/ls", "ls", "-h", "-l",  "-i", "/ken", NULL, environ);*/
	/*ret = execv("/bin/ls", ar);*/
	/*ret = execvp("ls", ar);*/
	/*ret = execve("/bin/ls", ar, env);*/
	//NULL 表示参数结束
	if (ret == -1)
	{
		printf("execl failed!\n");
		return -1;
	}
	/*system("ls -l -h -i");执行外部命令*/

	printf("main : end!\n");
	return 0;
}
