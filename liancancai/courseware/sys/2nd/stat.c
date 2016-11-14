#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

//第一个# 表示字符串连接符
//第二个# 表示八进制打印
#define PRI_O(a) printf(#a" = %#o\n", a)
#define PRI_I(a) printf(#a" = %d\n", a)

int main(int argc, char **argv)
{
	int ret;
	struct stat s;

	ret = stat(argv[1], &s);
	/*
	dev_t     st_dev;     ID of device containing file 
	ino_t     st_ino;     inode number 
	mode_t    st_mode;    protection 
	nlink_t   st_nlink;   number of hard links 
	uid_t     st_uid;     user ID of owner 
	gid_t     st_gid;     group ID of owner 
	dev_t     st_rdev;    device ID (if special file) 
	off_t     st_size;    total size, in bytes 
	blksize_t st_blksize; blocksize for filesystem I/O 
	blkcnt_t  st_blocks;  number of blocks allocated 
	time_t    st_atime;   time of last access 
	time_t    st_mtime;   time of last modification 
	time_t    st_ctime;   time of last status change 
	*/
	PRI_I(s.st_dev);    
    PRI_I(s.st_ino);    
    PRI_O(s.st_mode);   
    PRI_I(s.st_nlink);  
    PRI_I(s.st_uid);    
    PRI_I(s.st_gid);    
    PRI_I(s.st_rdev);   
    PRI_I(s.st_size);   
    PRI_I(s.st_blksize);
    PRI_I(s.st_blocks); 
    PRI_I(s.st_atime);  
    PRI_I(s.st_mtime);  
    PRI_I(s.st_ctime);  





	return 0;
}
