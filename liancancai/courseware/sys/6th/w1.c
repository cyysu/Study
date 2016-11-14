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

typedef void (FUNC)(void *);
typedef void (*sighandler_t)(int);


void hello(void *data)
{
	printf("%d : %d\n", (int *)data, time(NULL));
}

//抽象数据类型
struct node_t{
	int t;//表示循环时间
	int count;//表示统计时间
	void *data;//表示数据
	FUNC *func;//打印数据函数
	int flag;//表示是否循环打印
	struct node_t *next;
	struct node_t *prev;
};

//全局头
struct node_t head;

//实现插入函数
void add(int t, void *data, int flag)
{
	struct node_t *new = NULL;

	new = (struct node_t *)malloc(sizeof(struct node_t));
	if (new == NULL)
	{
		printf("malloc failed!\n");
		return ;
	}

	new->t = t;
	new->count = 0;
	new->data = data;
	new->func = hello;
	new->flag = flag;

	//后插
	new->next = &head;
	new->prev = head.prev;
	head.prev->next = new;
	head.prev = new;
}

void travel(int sig)
{
	struct node_t *tail = NULL;

	for (tail = head.next; tail != &head; tail = tail->next)
	{
		tail->count++;
		if (tail->count == tail->t)
		{
			tail->func(tail->data);
			tail->count = 0;
			if (tail->flag == 0)
			{
				tail->next->prev = tail->prev;
				tail->prev->next = tail->next;
				free(tail);
			}
		}
	}
}

void destroy(void)
{
	struct node_t *tail = NULL, *save = NULL;

	for (tail = head.next; tail != &head; tail = save)
	{
		save = tail->next;
		free(tail);
	}

	//重新设置成循环链表
	head.next = &head;
	head.prev = &head;
}
void init_timer(void)
{
	struct itimerval it;

	if (signal(SIGALRM, travel) == SIG_ERR)
	{
		printf("signal failed!\n");
		return ;
	}
	//设置循环时间
	it.it_interval.tv_sec = 1;
	it.it_interval.tv_usec = 0;

	//设置第一次执行时间
	it.it_value.tv_sec = 2;
	it.it_value.tv_usec = 0;

	if (setitimer(ITIMER_REAL, &it, NULL) == -1)
	{
		printf("setitimer failed!\n");
		return ;
	}

	//初始化链表
	head.next = &head;
	head.prev = &head;

	//退出函数
	atexit(destroy);
}
int main(int argc, char **argv)
{
	//实现定时器
	init_timer();

	add(1, (void *)11111, 1);
	add(3, (void *)33333, 0);
	add(5, (void *)55555, 1);
	add(8, (void *)88888, 0);
	add(10, (void *)10101, 1);
	add(13, (void *)13131, 1);

	getchar();
	return 0;
}






