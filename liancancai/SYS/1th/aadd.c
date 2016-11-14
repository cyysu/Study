#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

//实现a+
int main(int argc, char const *argv[])
{
	int fd = 0;
	int ret = 0;
	char buf[128];
	char buf_w[128] = "a+a+a+a+a+a+a+";
	              // O_RDWR   O_CREAT   O_APPEND
	fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND);
	ERRP(-1 == fd, open fd, goto ERR1);

	ret = read(fd, buf, sizeof(buf));
	ERRP(ret < 0, read buf, goto ERR2);

	printf("buf = %s", buf);

	ret = write(fd, buf_w, sizeof(buf_w));
	ERRP(ret < 0, write buf_w, goto ERR2);



	close(fd);
	return 0;

ERR2:
	close(fd);
ERR1:
	return -1;
}