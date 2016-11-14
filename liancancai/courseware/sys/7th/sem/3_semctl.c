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
#include<sys/sem.h>
#include <share.h>

//表示加锁
void lock(int sem, int num)
{
	struct  sembuf buf;
	buf.sem_num = num;
	buf.sem_op = -1;
	buf.sem_flg = 0;

	semop(sem, &buf, 1);
}
//表示解锁
void unlock(int sem, int num)
{
	struct  sembuf buf;

	buf.sem_num = num;
	buf.sem_op = 1;
	buf.sem_flg = 0;

	semop(sem, &buf, 1);
}


//子进程执行操作
void do_work(int fd, int sem, int num)
{
	char buf[128];
	int i, j, count = 0;
	/*printf("work_pid : %d\n", getpid());*/

	
	//加锁
	lock(sem, num);
	for (;;)
	{
		snprintf(buf, sizeof(buf), "child : pid = %d count = %d\n", getpid(), count++);
		if (count == 101)
		{
			unlock(sem, num);
			exit(0);
		}
		for (i = 0; i < strlen(buf); i++)
		{
			write(fd, &buf[i], 1);
		}
	}
	//解锁
	unlock(sem, num);
	close(fd);
	exit(0);
}

int main(int argc, char **argv)
{
	key_t key;
	int sem;
	int i, fd;
	//获取关键字
	ERRP((key = ftok("/", 1234)) == -1, "ftok failed", goto ERR1);

	//创建信号锁
	ERRP((sem = semget(key, 1, IPC_CREAT)) == -1, "semget failed", goto ERR1);

	//设置已把锁
	ERRP(semctl(sem, 0, SETVAL, 1) == -1, "semctl failed", goto ERR1);
	

	fd = open("./test", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		return -1;
	}

	for (i = 0; i < 10; i++)
	{
		if (fork() == 0)
		{
			do_work(fd, sem, 0);
		}
	}

	for (i = 0; i < 10; i++)
	{
		wait(NULL);
	}

	semctl(sem, 0, IPC_RMID);
	return 0;
ERR1:
	return -1;
}
