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
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <share.h>

int main(int argc, char **argv)
{
	key_t key;
	int shm;
	void *p = NULL;

	// 创建关键字
	key = ftok("/tmp", 112233);
	ERRP(key == -1, "ftok failed!", goto ERR1);

	printf("key = %#x\n", key);
	// 2 创建共享内存
	/*shm = shmget(key, 1024, IPC_CREAT | 0666);*/
	/*shm = shmget(key, 1024, IPC_CREAT | IPC_EXCL);*/
	shm = shmget(key, 1024, IPC_CREAT);
	ERRP(shm == -1, "shmget failed", goto ERR1);

	printf("shm = %d\n", shm);
	printf("success!\n");

	
	// 3 映射共享内存
	p = shmat(shm, NULL, 0);
	ERRP(p == (void *)-1, "shmat failed", goto ERR1);

	memset(p, 0, 1024);
	printf("p = %s\n", p);
	//输入数据到共享内存中
	strcpy(p, "hello");
	strcpy(p, "wor");
	//获取数据
	printf("p = %s\n", p);

	

	printf("p = %p\n", p);
	return 0;
ERR1:	
	return -1;
}
