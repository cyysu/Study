#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <shadow.h>
#include <time.h>
#include <dirent.h>
#include <glob.h>

int main(int argc, char **argv)
{
	int ret;

    /*
	 *ret = lchown(argv[1], 501, 503);
	 *if (ret == -1)
	 *{
	 *    perror("chown");
	 *    return -1;
	 *}
     */

	int mode;
	printf("please input file mode : ");
	scanf("%o", &mode);

	printf("mode = %d\n", mode);
	printf("mode = %o\n", mode);
	chmod("./test", mode);
	printf("success!\n");
	return 0;
}
