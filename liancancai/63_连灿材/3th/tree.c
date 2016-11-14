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
#include <crypt.h>
#include <time.h>
#include <dirent.h>
#include <glob.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>



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

void tree(char *path)
{
	static level = 0;
	int i;
	DIR *dirp = NULL;
	struct dirent *dir = NULL;
	char buf[256] = {};
	// int stat(const char *path, struct stat *buf);



	dirp = opendir(path);
	ERRP(NULL == dirp, opendir, goto ERR1);

	chdir(path);

	while ((dir = readdir(dirp)) != NULL)
	{
		if(strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
		{
			continue;
		}

		if (DT_DIR == dir->d_type)
		{

			for (i = 0; i < level; i++)
			{
				printf("    ");
			}
			level ++;
			printf("%s\n", dir->d_name);

			tree(dir->d_name);

			level--;
		}
		else if (DT_LNK == dir->d_type)
		{
			readlink(dir->d_name, buf, sizeof(buf));

			for (i = 0; i < level; i++)
			{
				printf("    ");
			}
			printf("\033[34m%s\033[0m -> %s\n", dir->d_name, buf);
		}
		else
		{
			for (i = 0; i < level; i++)
			{
				printf("    ");
			}
			printf("%s\n", dir->d_name);
		}
	}

	chdir("..");
	closedir(dirp);
	return;
ERR1:
	return;
}

int main(int argc, char **argv)
{
	// DIR *dirp = NULL;
	// struct dirent *dir = NULL;
	// int i;

	// dirp = opendir(argv[1]);
	// ERRP(NULL == dirp, opendir, goto ERR1);
	tree(argv[1]);

	//    // struct dirent {
 //    //            ino_t          d_ino;       /* inode number */
 //    //            off_t          d_off;       /* not an offset; see NOTES */
 //    //            unsigned short d_reclen;     length of this record 
 //    //            unsigned char  d_type;      /* type of file; not supported
 //    //                                           by all filesystem types */
 //    //            char           d_name[256]; /* filename */
 //    //        };

	// while ((dir = readdir(dirp)) != NULL)
	// {
	// 	printf("%s\n", dir->d_name);
	// }


	return 0;
// ERR1:

// 	return -1;
}
