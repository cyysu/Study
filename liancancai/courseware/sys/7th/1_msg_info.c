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

int main(int argc, char **argv)
{
	key_t key;
	int msg, ret;
	struct msqid_ds buf;

	key = ftok("/tmp", 12345);
	if (key == -1)
	{
		printf("ftok failed!\n");
		return -1;
	}

	msg = msgget(key, IPC_CREAT | 0777);
	if (msg == -1)
	{
		printf("masgget failed!\n");
		return -1;
	}

    /*
	 *ret = msgsnd(msg, "hello", 5, 0);
	 *if (ret == -1)
	 *{
	 *    printf("msgsnd failed!\n");
	 *    return -1;
	 *}
     */

	//info 
	ret = msgctl(msg, IPC_STAT, &buf);
	if (ret == -1)
	{
		printf(",sgctl failed!\n");
		return -1;
	}

	/*printf("key = %#x\n", buf.msg_perm.key);*/
	printf("types = %ld\n", buf.__msg_cbytes);
	printf("num = %d\n", buf.msg_qnum);
	
	return 0;
}








