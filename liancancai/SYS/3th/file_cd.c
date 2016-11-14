#define _GNU_SOURCE


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
	char buf[128] = {};
	char *p = NULL;

	 // int chdir(const char *path);


	// char *getcwd(char *buf, size_t size);

	// char *getwd(char *buf);

	// char *get_current_dir_name(void);

	// p = getcwd(buf, sizeof(buf));
	// ERRP(NULL == p, getcwd, goto ERR1);

	// printf("getcwd = %s\n", buf);

	// p = get_current_dir_name();
	printf("%s\n", get_current_dir_name());

	chdir(argv[1]);

	printf("%s\n", get_current_dir_name());
	return 0;
ERR1:
	return -1;
}
