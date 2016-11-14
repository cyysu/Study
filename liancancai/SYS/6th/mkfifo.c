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

int main(int argc, char **argv)
{
	   // int mkfifo(const char *pathname, mode_t mode);
	int ret;
	int fd;
	char buf[128];

	system("rm ./test01 -f");
	
	umask(0);

	ret = mkfifo("./test01", 0755);
	ERRP(-1 == ret, mkfifo, goto ERR1);
	// printf("ret = %d\n", ret);

	fd = open("./test01", O_RDWR);
	ERRP(-1 == fd, open, goto ERR1);

	ret = fork();
	ERRP(-1 == ret, fork, goto ERR1);

	if (0 == ret)//child
	{
		ret = write(fd, "hello", 5);
		ERRP(ret <= 0, write, goto ERR1);

		close(fd);
		exit(0);
	}

	wait(NULL);

	ret = read(fd, buf, sizeof(buf));
	ERRP(ret <= 0, read, goto ERR1);

	printf("buf = %s\n", buf);

	close(fd);

	return 0;
ERR1:
	return -1;
}
