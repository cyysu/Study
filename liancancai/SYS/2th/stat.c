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

#define PRI_I(string) printf(#string" = %d\n", string)
#define PRI_O(string) printf(#string" = %#o\n", string)

//测试stat
int main(int argc, char const *argv[])
{
	struct stat s;

	  // struct stat {
   //             dev_t     st_dev;     /* ID of device containing file */
   //             ino_t     st_ino;     /* inode number */
   //             mode_t    st_mode;    /* protection */
   //             nlink_t   st_nlink;   /* number of hard links */
   //             uid_t     st_uid;     /* user ID of owner */
   //             gid_t     st_gid;     /* group ID of owner */
   //             dev_t     st_rdev;     device ID (if special file) 
   //             off_t     st_size;    /* total size, in bytes */
   //             blksize_t st_blksize; /* blocksize for filesystem I/O */
   //             blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
   //             time_t    st_atime;   /* time of last access */
   //             time_t    st_mtime;   /* time of last modification */
   //             time_t    st_ctime;   /* time of last status change */
   //         };

	stat (argv[1], &s);


	PRI_I(s.st_dev);
	return 0;
}