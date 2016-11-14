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
	char buf[128] = "mks_XXXXXX";
	int i;
	int ret;

	for (i = 0; i < 10; i++)
	{
		ret = mkstemp(buf);
		ERRP(-1 == ret, mkstemp, goto ERR1);

		printf("%s\n", buf);

		strncpy(buf, "mks_XXXXXX", sizeof(buf));
	}
	
	return 0;
ERR1:
	return -1;
}
