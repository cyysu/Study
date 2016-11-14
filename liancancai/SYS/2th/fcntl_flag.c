#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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


//测试fcntl
int main(int argc, char const *argv[])
{
	int fd;
	int ret;
	int flag;
	char buf[128] = "fcntl test";

	fd = open(argv[1], O_WRONLY | O_CREAT);
	ERRP(-1 == fd, open fd, goto ERR1);

	ret = write(fd, buf, sizeof(buf));
	ERRP(ret <= 0, write fd, goto ERR2);

	flag = fcntl(fd, F_GETFL);
	ERRP(-1 == flag, fcntl fd, goto ERR2);

	printf("flag = %#o\n", flag);

	flag |= O_APPEND;

	fcntl(fd, F_SETFL, flag);
	ret = write(fd, buf, sizeof(buf));
	ERRP(ret <= 0, write fd, goto ERR2);

	close(fd);
	
	return 0;
ERR2:
	close(fd);
ERR1:
	return -1;
}