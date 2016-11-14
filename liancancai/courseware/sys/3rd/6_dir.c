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

int main(int argc, char **argv)
{
	DIR *dir = NULL;
	int ret;

    /*
	 *ret = chmod(argv[1], 0777);
	 *if (ret == -1)
	 *{
	 *    printf("chmod faied!\n");
	 *    return -1;
	 *}
	 *printf("chmod success!\n");
	 *getchar();
     */
	dir = opendir(argv[1]);
	if (dir == NULL)
	{
		printf("opendir failed!\n");	
		return -1;
	}
	printf("opendir success!\n");

	/*free(dir);*/

	struct dirent *file = NULL;

	while(1)
	{
		file = readdir(dir);
		if (file == NULL)
		{
			printf("readdir failed!\n");
			closedir(dir);
			return -1;
		}
		printf("readdir success!\n");

		if (file->d_name[0] == '.')
			continue;
        /*
		 *printf("d_ino = %d\n", file->d_ino);
		 *printf("d_off = %d\n", file->d_off);
		 *printf("d_reclen = %d\n", file->d_reclen);
         */
		printf("d_type = %o\n", file->d_type);
		printf("d_name = %s\n", file->d_name);
		printf("================\n");
	}
    /*
	 *chdir(argv[1]);
	 *creat("./file1", 0666);
     */

	closedir(dir);
	return 0;
}
