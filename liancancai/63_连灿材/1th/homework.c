#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//测试create 的权限

//1 若文件不存在，则创建
//2 若文件存在， 则清空
//3 具有写的权限
int main(int argc, char const *argv[])
{
	int fd = 0;
	int ret = 0;
	char buf[128];
	char buf_w[128] = "creat write test\n";
	umask(0);

	ret = creat(argv[1], 0755);

	// read(buf, sizeof(buf), ret);
	write(ret, buf_w, sizeof(buf_w));

	// printf("buf = %s\n", buf);
	// printf("ret = %d\n", ret);



	return 0;
}
