#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//cp src dest
// src ->argv[1] -> open -> O_RDONLY
// dest -> argv[2] -> open -> O_WRONLY | O_CREAT | O_TRUNC => creat
int main(int argc, char **argv)
{
	int fdr, fdw, ret;
	char buf[10] = {};

	fdr = open(argv[1], O_RDONLY);
	if (fdr == -1)
	{
		perror("open");
		return -1;
	}
	fdw = creat(argv[2], 0666);
	if (fdw == -1)
	{
		perror("creat");
		close(fdr);
		return -1;
	}

	while((ret = read(fdr, buf, sizeof(buf) - 1)) > 0)
	{
        /*
		 *printf("buf = %s\n", buf);
		 *getchar();
         */
		write(fdw, buf, strlen(buf));
		memset(buf, 0, sizeof(buf));
	}
	return 0;
}
