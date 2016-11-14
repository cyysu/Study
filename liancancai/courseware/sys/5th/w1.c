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

#define NUM 10
#define MIN 3000
#define MAX 6000
#define STEP ((MAX - MIN) / NUM)

//求素数 ，就是只能被1和本身整除的数
int prime(int min, int max)
{
	int i, j;
	int count = 0;

	printf("====pid(%d ~ %d) : %d \n", min, max, getpid());
	for (i = min; i < max; i++)
	{
		for (j = 2; j < i; j++)	
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j == i)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n====== %d =====\n", count);
	return count;
}

int main(int argc, char **argv)
{
	int i, ret;
	int status;
	int count = 0;

	for (i = 0; i < NUM; i++)
	{
		ret = fork();
		if (ret == 0)
		{
			exit(prime(MIN + i * STEP, MIN + (i + 1) * STEP));
			/*printf("pid : %d hello!\n", getpid());*/
			/*exit(0);*/
		}
	}

	//等待10个进程退出
	for (i = 0; i < NUM; i++)
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			count += WEXITSTATUS(status);
		}
	}
	printf("count = %d\n", count);
	/*printf("count = %d\n", prime(3000, 6000));*/
	return 0;
}
