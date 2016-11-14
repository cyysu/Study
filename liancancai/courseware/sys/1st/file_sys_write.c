#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	FILE *fp = NULL;
	int ret;
	int fd;

	#if 1
	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC);
	ret = write(fd, "hello", 5);

	#else

	fp = fopen(argv[1], "w");


	char buf[128] = "hello\n";
	// 1
	/*printf("hello!");*/

	ret = fwrite(buf, 1, 6, fp);
	#endif
	printf("ret = %d\n", ret);
	while(1)
		sleep(1);

	/*getchar();*/
	return 0;
}
