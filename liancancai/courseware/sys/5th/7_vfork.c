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

int main(int argc, char **argv)
{
	int count = 123456;
	int a = 456;

	int fp = open();

	if (vfork())
	{
		printf("parent! count = %d pid : %d\n", count, getpid());
		/*printf("num = %d\n", num);*/
	}
	else
	{
		/*sleep(1);*/
		count = 54321;
		int num = 123;
		printf("child! pid : %d a = %d\n\n", getpid(), a);
		exit(0);
		
		/*return 0;*/
	}
	return 0;
}
