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
	int msg;
	int ret;
	char buf[128];
	key_t key;

	// 1 获取关键字
	key = ftok("/tmp", 1122);
	printf("key = %#x\n", key);
	//2 创建消息队列
	msg = msgget(key, IPC_CREAT | 0666);
	if (msg == -1)
	{
		printf("msgget failed!\n");
		return -1;
	}
	printf("msg = %d\n", msg);


	// 3 接受数据
	ret = msgrcv(msg, buf, sizeof(buf), 0, 0);
	if (ret == -1)
	{
		printf("msgsnd failed!\n");
		return -1;
	}

	printf("ret = %d\n", ret);
	printf("buf = %s\n", buf);

	return 0;
}
