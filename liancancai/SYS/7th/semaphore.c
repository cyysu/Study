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
#include <sys/sem.h>

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

#define LOCK -1
#define UNLOCK 1

void sem_lock(int semid, int num, int op)
{
	struct sembuf buf;
	buf.sem_num = num;
	buf.sem_op = op;
	buf.sem_flg = 0;

	semop(semid, &buf, 1);
}

void do_work(int fd, int semid, int num)
{
	int i, j;
	char buf[128];

	sem_lock(semid, num, LOCK);

	for (j = 0; j < 10; j++)
	{
		for (i = 0; i < 100; i++)
		{
			write(fd, "a", 1);
		}
		write(fd, "end\n\n", 5);
	}

	sem_lock(semid, num, UNLOCK);
}

int main(int argc, char **argv)
{
	    // int semget(key_t key, int nsems, int semflg);
	key_t key;
	int ret;
	int semid;
	int i;
	int fd;

	key = ftok("/liancancai", 1234);
	ERRP(-1 == key, ftok, goto ERR1);
						 
	semid = semget(key, 1, IPC_CREAT);
	ERRP(-1 == semid, semget, goto ERR1);

	printf("semaphoreid = %d\n", semid);


	// int semop(int semid, struct sembuf *sops, unsigned nsops);

	         // unsigned short sem_num;  /* semaphore number */
          //  short          sem_op;   /* semaphore operation */
          //  short          sem_flg;  /* operation flags */

	     // int semctl(int semid, int semnum, int cmd, ...);
	     //  SETVAL 
	ret = semctl(semid, 0, SETVAL, 1);//0表示信号量索引号，　１开始解锁（正数表示解锁）
	ERRP(-1 == ret, semctl, goto ERR1);

	fd = open("./test", O_RDWR | O_CREAT | O_TRUNC);
	ERRP(-1 == fd, open, goto ERR1);


	for (i = 0; i < 10; i++)
	{
		ret = fork();
		ERRP(-1 == ret, fork, goto ERR1);

		if (0 == ret)
		{
			do_work(fd, semid, 0);
			exit(0);
		}
	}

	for (i = 0; i < 10; i++)
	{
		wait(NULL);
	}

	ret = semctl(semid, 0,  IPC_RMID);
	
	ERRP(-1 == ret, semctl, goto ERR1);


	return 0;
ERR1:
	return -1;
}

