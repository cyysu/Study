#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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

//测试 dup2
int main(int argc, char **argv)
{
	int fd1, fd2;
	int ret;
	char buf[128] = "dup2 test\n";

	fd1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC);	
	ERRP(-1 == fd1, open fd1, goto ERR1);

	ret = write(fd1, buf, sizeof(buf));
	ERRP(ret <= 0, write fd1, goto ERR2);

	fd2 = dup2(fd1, 8);
	
	printf("stdout test\n");
	printf("fd2 = %d\n", fd2);

	ret = write(fd2, buf, sizeof(buf));
	ERRP(ret <= 0, write fd2, goto ERR2);


	close(fd1);
	return 0;
ERR2:
	close(fd1);
ERR1:
	return -1;
}
