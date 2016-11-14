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

//测试dup
int main(int argc, char const *argv[])
{
	int fd1, fd2;
	int ret;
	char buf[20] = "dup test  ";

	fd1 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC);
	ERRP(-1 == fd1, open fd1, goto ERR1);

	ret = write(fd1, buf, sizeof(buf));
	ERRP(ret <=0, write fd1, goto ERR2);

	fd2 = dup(fd1);

	ret = write(fd2, buf, sizeof(buf));
	ERRP(ret <= 0, write fd2, goto ERR2);

	close(fd1);
	close(fd2);
	return 0;
ERR2:
	close(fd1);
ERR1:
	return -1;
}