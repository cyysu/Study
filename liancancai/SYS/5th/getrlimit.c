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

int main(int argc, char **argv)
{
	// int getrlimit(int resource, struct rlimit *rlim);
	// int setrlimit(int resource, const struct rlimit *rlim);
	// struct rlimit {
	// 	rlim_t rlim_cur;  /* Soft limit */
	// 	rlim_t rlim_max;  /* Hard limit (ceiling for rlim_cur) */
	// };
	// RLIMIT_NOFILE
	struct rlimit rlim;
	int ret;

	ret = getrlimit(RLIMIT_NOFILE, &rlim);
	ERRP(-1 == ret, getrlimit, goto ERR1);

	printf("rlim_cur = %ld\n", rlim.rlim_cur);
	printf("rlim_max = %ld\n", rlim.rlim_max);

	rlim.rlim_cur = 2048;

	ret = setrlimit(RLIMIT_NOFILE, &rlim);
	ERRP(-1 == ret, getrlimit, goto ERR1);

	printf("rlim_cur = %ld\n", rlim.rlim_cur);

	return 0;
ERR1:
	return -1;
}
