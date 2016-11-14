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

void time_done(int a)
{
	printf("the time is over\n");
}

int main(int argc, char **argv)
{
	// int getitimer(int which, struct itimerval *curr_value);
	  // int setitimer(int which, const struct itimerval *new_value,
   //                   struct itimerval *old_value);

	  // struct itimerval {
   //             struct timeval it_interval; /* next value */
   //             struct timeval it_value;    /* current value */
   //         };

   //         struct timeval {
   //             time_t      tv_sec;         /* seconds */
   //             suseconds_t tv_usec;        /* microseconds */
   //         };

	// ITIMER_REAL    decrements in real time, and delivers SIGALRM upon expiration.

 //       ITIMER_VIRTUAL decrements only when the process is executing, and delivers SIGVTALRM upon expiration.
	struct itimerval tv;
	int ret;

	signal(SIGVTALRM, time_done);

	tv.it_interval.tv_sec = 0;
	tv.it_interval.tv_usec = 500000;

	tv.it_value.tv_sec = 2;
	tv.it_value.tv_usec = 500000;

	ret = setitimer(ITIMER_VIRTUAL, &tv, NULL);
	if (-1 == ret)
	{
		printf("setitimer failed\n");
		return -1;
	}

	while(1)
	{
		// pause();
	}

	return 0;
}
