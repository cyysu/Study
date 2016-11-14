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

struct cls_t{
	char name[128];
	int age;
	char sex;
	double result;
};


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

	printf("name = %s\n", ((struct cls_t *)p)->name);
	printf("age = %d\n", ((struct cls_t *)p)->age);
	printf("sex = %c\n", ((struct cls_t *)p)->sex);
	printf("result = %lg\n", ((struct cls_t *)p)->result);
	//获取数据
	// printf("p = %s\n", p);

	// printf("p = %p\n", p);
	return 0;
ERR1:	
	return -1;
}
