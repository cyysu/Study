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

//实现w+
int main(int argc, char **argv)
{
	int fd = 0;
	char buf[128];
	char buf_w[128] = "buf_w+ test";
	int ret = 0;

	fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC);
	ERRP(-1 == fd, open fd, goto ERR1);

	ret = write(fd, buf_w, sizeof(buf));
	ERRP(-1 == fd, write fd, goto ERR2);

	close(fd);
	return 0;
ERR2:
	close(fd);	

ERR1:
	return -1;
}
