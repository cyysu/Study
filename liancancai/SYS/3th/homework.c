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
#include <errno.h>

extern int erron;
int count = 1;

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
	struct dirent *dir_information = NULL;
	struct stat s;
	int ret;
	char *retp = NULL;
	DIR *dir = NULL;
	char pwd [128] = {};

	ret = chdir(path);//切换到目的目录
	ERRP(-1 == ret, chdir, goto ERR1);

	retp = getcwd(pwd, sizeof(pwd));//打印当前路径
	ERRP(NULL == retp, getcwd, goto ERR1);
	// printf(" ,pwd = %s\n", pwd);

	dir = opendir(pwd);//打开目录

	if(errno != 0)
	{
		printf("%s\n", strerror(errno));
	}

	ERRP(NULL == dir, opendir, goto ERR1);
	
	while(1)
	{
		dir_information =  readdir(dir);

		if(NULL == dir_information)
		{
			// printf("NULL");
			break;
		}:

		if(strcmp(dir_information->d_name,".") == 0)
		{
			dir_information =  readdir(dir);
		}
		else if(strcmp(dir_information->d_name,"..") == 0)
		{
			dir_information =  readdir(dir);
		}
		else
		{
			// // sleep(1);
			// retp = getcwd(pwd, sizeof(pwd));//打印当前路径
			// ERRP(NULL == retp, getcwd, goto ERR1);
			printf(" \033[31mpwd = %s\033[0m %d \n", pwd, count);
			// printf("  count = %d\n", count);
			// count ++;
			printf("%s ", dir_information->d_name);
				
			ret = stat(dir_information->d_name, &s);

			if(errno != 0)
			{
				// printf("%d\n", errno);
				// printf("%d\n", ENOTDIR);
				printf("%s\n", strerror(errno));
			}

			ERRP(-1 == ret, stat, goto ERR1);

			if(S_ISDIR(s.st_mode))
			{

				tree(dir_information->d_name);

				// ret = chdir("..");//切换到目的目录
				// // ret = chdir("..");//切换到目的目录
				// ERRP(-1 == ret, chdir, goto ERR1);

				// retp = getcwd(pwd, sizeof(pwd));//打印当前路径
				// ERRP(NULL == retp, getcwd, goto ERR1);
				// // printf(" ,pwd = %s\n", pwd);

				// dir = opendir(pwd);//打开目录
			}
			printf("\n");
			// retp = getcwd(pwd, sizeof(pwd));//打印当前路径
			// ERRP(NULL == retp, getcwd, goto ERR1);
			// printf("%s\n", pwd);
			dir_information =  readdir(dir);
		}
	}

	closedir(dir);
	chdir("..");//切换到目的目录

	return ;
ERR1:
	return ;
}

int main(int argc, char **argv)
{
	DIR *dir = NULL;
	char *retp = NULL;
	int ret;
	char pwd[128] = {};
	struct dirent *dir_information = NULL;
	struct stat s;
	// DIR *opendir(const char *name);

	 // char *getcwd(char *buf, size_t size);

	// struct dirent *readdir(DIR *dirp);
	//  struct dirent {
	//     ino_t          d_ino;       /* inode number */
	//     off_t          d_off;       /* not an offset; see NOTES */
	//     unsigned short d_reclen;     length of this record 
	//     unsigned char  d_type;      /* type of file; not supported
	//                                    by all filesystem types */
	//     char           d_name[256]; /* filename */
	// };



	// retp = getcwd(pwd, sizeof(pwd));//打印当前路径
	// ERRP(NULL == retp, getcwd, goto ERR1);
	// printf("%s\n", pwd);


	// int stat(const char *path, struct stat *buf);
	// struct stat {
	// dev_t     st_dev;     /* ID of device containing file */
	// ino_t     st_ino;     /* inode number */
	// mode_t    st_mode;    /* protection */
	// nlink_t   st_nlink;   /* number of hard links */
	// uid_t     st_uid;     /* user ID of owner */
	// gid_t     st_gid;     /* group ID of owner */
	// dev_t     st_rdev;     device ID (if special file) 
	// off_t     st_size;    /* total size, in bytes */
	// blksize_t st_blksize; /* blocksize for filesystem I/O */
	// blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
	// time_t    st_atime;   /* time of last access */
	// time_t    st_mtime;   /* time of last modification */
	// time_t    st_ctime;   /* time of last status change */
	// };

	   // S_ISDIR(m)  directory?
	tree(argv[1]);
	// ret = stat(argv[1], &s);
	// ERRP(-1 == ret, stat, goto ERR1);

	// if(S_ISDIR(s.st_mode))
	// {
	// 	printf("Is a directory\n");
	// }




	dir = opendir(argv[1]);//打开目录
	ERRP(NULL == dir, opendir, goto ERR1);

	// dir_information =  readdir(dir);
	// ERRP(NULL == dir_information, readdir, goto ERR2);

	// dir_information =  readdir(dir);
	// while(dir_information != NULL)
	// {
	// 	printf("%s\n", dir_information->d_name);
	// 	dir_information =  readdir(dir);
	// }

	// ret = chdir(argv[1]);//切换到目的目录
	// ERRP(-1 == ret, chdir, goto ERR2);

	// retp = getcwd(pwd, sizeof(pwd));//打印当前路径
	// ERRP(NULL == retp, getcwd, goto ERR2);
	// printf("%s\n", pwd);

	ret = closedir(dir);
	ERRP(-1 == ret, closedir, goto ERR1);

	return 0;
ERR2:
	closedir(dir);
ERR1:
 	return -1;
}
