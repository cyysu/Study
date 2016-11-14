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
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include <sys/ipc.h>
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
	char name[123];
	int age;
	char sex;
	double grade;
};

int main(int argc, char **argv)
{
	// int shmget(key_t key, size_t size, int shmflg);
	 // key_t ftok(const char *pathname, int proj_id);
	// void *shmat(int shmid, const void *shmaddr, int shmflg);
	// int shmdt(const void *shmaddr);
    // int shmctl(int shmid, int cmd, struct shmid_ds *buf);


	key_t key;
	int ret;
	void *pret = NULL;
	int shmid;
	struct cls_t stu;

	key = ftok("/liancancai", 1234);
	ERRP(-1 == key, ftok, goto ERR1);

	shmid = shmget(key, 1024, IPC_CREAT | 0666);
	ERRP(-1 == shmid, shmget, goto ERR1);

	printf("shmid = %d\n", shmid);

	pret = shmat(shmid, NULL, 0);//0表示可读可写
	ERRP((void *)-1 == pret, shmat, goto ERR1);

	memcpy(&stu, pret, sizeof(struct cls_t));

	printf("name = %s\n", stu.name);
	printf("age = %d\n", stu.age);
	printf("sex = %c\n", stu.sex);
	printf("grade = %lf\n", stu.grade);

	ret = shmdt(pret);//取消映射
	ERRP(-1 == ret, shmdt, goto ERR1);

	 // IPC_RMID
	ret = shmctl(shmid, IPC_RMID, NULL);
	ERRP(-1 == ret, shmctl, goto ERR1);

	return 0;
ERR1:
	return -1;
}
