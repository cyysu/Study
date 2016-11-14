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
#include <crypt.h>
#include <time.h>
#include <dirent.h>
#include <glob.h>
#include <signal.h>
#include <sys/wait.h>

#define INFORMATION   do{					\
		printf("file: %s\n", __FILE__);		\
		printf("func: %s\n", __func__);		\
		printf("line: %d\n", __LINE__);		\
}while(0)

#define ERRP(condition, string, ret) do{	\
		if(condition)						\
		{									\
			printf(#string" failed\n");		\
			INFORMATION;					\
			ret;							\
		}									\
}while(0)

#define NUM 10
#define START_NUM 3000
#define END_NUM 6000
#define STEP ((END_NUM - START_NUM) / NUM)

int prime(int start_num, int end_num)
{
	int j, i;
	int count = 0;

	for (i = start_num; i < end_num; i++)
	{
		for (j = 2; j < i; j ++)
		{
			if (i % j == 0)
			{
				break;
			}
		}

		if (j == i)
		{
			count ++;
			// printf("%d\n", j);
		}
	}

	return count;
}

int main(int argc, char **argv)
{
	int ret;
	int count = 0;
	int i;
	int status;
	for (i = 0; i < NUM; i++)
	{
		ret = fork();
		ERRP(-1 == ret, fork, goto ERR1);

		if (0 == ret)//child
		{
			count = prime(START_NUM + STEP * i, START_NUM + ( 1 + i) * STEP);

			exit(count);
		}	
	}

	for (i = 0; i < NUM; i ++)
	{
		wait(&status);

		if (WIFEXITED(status))
		{
			count += WEXITSTATUS(status);
		}
	}
		
	printf("count = %d\n", count);

	return 0;
ERR1:
	return -1;
}
