#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	char buf[128];
	int flag;


	flag = fcntl(0, F_GETFL);//取出文件标志位

	flag |= O_NONBLOCK;//表示取消阻塞
	fcntl(0, F_SETFL, flag);//设置回去

	sleep(3);
	printf("flag = %#o\n", flag);
	read(0, buf, sizeof(buf));

	printf("buf = %s", buf);
	return 0;
}
