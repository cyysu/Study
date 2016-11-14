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

//测试lseek
int main(int argc, char ** argv)
{
	int fd;
	int ret;
	char buf[24] = "1";
	char buf_read[300];

	fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC);
	ERRP(-1 == fd, open fd, goto ERR1);
	
	lseek(fd, 1000, SEEK_SET);

	ret = write(fd, buf, sizeof(buf));
	// ERRP(ret <= 0, write fd, goto ERR2);


	// lseek(fd, 1000, SEEK_SET);

	// ret = read(fd, buf_read, sizeof(buf_read));
	// printf("ret = %d\n", ret);
	// ERRP(ret < 0, read fd, goto ERR2);

	// printf("buf_read = %s", buf_read);

	close(fd);
	return 0;
ERR2:
	close(fd);
ERR1:
	return -1;
}