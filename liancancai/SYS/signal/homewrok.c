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
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>

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

typedef void (*sighandler_t)(int);

typedef void (*FUN)(int);

// void hello(int sign)
// {
	
// 	switch(sign)
// 	{
// 		case 1:
// 			printf("11111\n");
// 			break;
// 		case 3:
// 			printf("33333\n");
// 			break;
// 		case 5:
// 			printf("55555\n");
// 			break;
// 		case 8:
// 			printf("88888\n");
// 			break;
// 		case 10:
// 			printf("10101\n");
// 			break;
// 		default:
// 			break;
// 	}
// }

void hello1(int sign)
{
	printf("11111\n");
	exit(0);
}

void hello3(int sign)
{
	printf("33333\n");
}

void hello5(int sign)
{
	printf("55555\n");
}

void hello8(int sign)
{
	printf("88888\n");
}

void hello10(int sign)
{
	printf("10101\n");
}

int my_setitimer(int value_sec, int value_usec, int interval_sec, int interval_usec)
{
	struct itimerval tv;
	int ret;

	tv.it_value.tv_sec = value_sec;
	tv.it_value.tv_usec = value_usec;

	tv.it_interval.tv_sec = interval_sec;
	tv.it_interval.tv_usec  = interval_usec; 

	ret = setitimer(ITIMER_REAL, &tv, NULL);
	ERRP(ret != 0, setitimer, goto ERR1);

	return 0;
ERR1:
	return -1;
}

void my_exit(int sign)
{
	exit(0);
}

void my_func(int sign)
{
	int ret;
	FUN p = NULL;

	ret = fork();
	ERRP(-1 == ret, fork, goto ERR1);

	if (0 == ret)//child
	{
		p = signal(SIGALRM, hello1);
		if (SIG_ERR == p)
		{
			printf("signal failed\n");
			return ;
		}

		ret = my_setitimer(0, 1, 0, 500000);
		ERRP(-1 == ret, my_setitimer, goto ERR1);
	}

	wait(NULL);
	return ;

ERR1:
	return ;
}

int main(int argc, char **argv)
{
	// 1 -> 11111 1
	// 3 -> 33333 0
	// 5 -> 55555 1
	// 8 -> 88888 0
	// 10 ->10101 1

	struct itimerval tv;
	int ret;
	FUN p = NULL;
	int i;

	printf("main start...\n");

	p = signal(SIGALRM, my_func);
	if (SIG_ERR == p)
	{
		printf("signal failed\n");
		return -1;
	}

	ret = my_setitimer(1, 0, 1, 0);
	ERRP(-1 == ret, my_setitimer, goto ERR1);

	p = signal(SIGALRM, hello1);
	if (SIG_ERR == p)
	{
		printf("signal failed\n");
		return -1;
	}

	// for (i = 0; i < 10; i++)
	// {
	// 	pause();
	// 	if (5 == i)
	// 	{
	// 		ret = my_setitimer(1, 0, 0, 300000);
	// 		ERRP(-1 == ret, my_setitimer, goto ERR1);
	// 	}
	// }
	while(1);

	printf("main end...\n");

	return 0;
ERR1:
	return -1;
}

