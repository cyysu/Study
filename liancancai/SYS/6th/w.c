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


struct node_t {
	struct node_t *prev;
	struct node_t *next;
	void *data;
};

struct timer{
	int count;
	int time;
	int flag;
	void *string;
};

struct llist_t{
	int size;
	int num;
	struct node_t node;
};

struct llist_t head;

void head_init(void)
{
	head.node.next = &head.node;
	head.node.prev = &head.node;
	head.num = 0;
	head.size = sizeof(struct timer);
}

// tim.count = 0;
// 	tim.time = 1;
// 	tim.flag = 1;
// 	tim.string = "11111";

void append(int count, int time, int flag, void *s)
{
	struct timer tim;
	tim.count = count;
	tim.time = time;
	tim.flag = flag;
	tim.string = s;

	void *data = NULL;

	data = &tim;

	struct node_t *new = NULL;

	new = (struct node_t *)malloc(sizeof(struct node_t));
	ERRP(NULL == new, malloc new, goto ERR1);

	new->data = (void *)malloc(head.size);
	ERRP(NULL == new->data, malloc new->data, goto ERR1);

	memcpy(new->data, data, head.size);

	new->next = &head.node;
	new->prev = head.node.prev;
	head.node.prev->next = new;
	head.node.prev = new;

ERR1:
	return ;
}

void p_count(void *data)
{
	printf("%d\n", ((struct timer *)data)->count);
}

void p_time(void *data)
{
	printf("count = %d\n", ((struct timer *)data)->time);
}

void p_flag(void *data)
{
	printf("count = %d\n", ((struct timer *)data)->flag);
}

void p_string(void *data)
{
	printf("string = %s | %ld\n", (char *)(((struct timer *)data)->string), time(NULL));
}

void ls(void *data)
{
	printf("count = %d\n", ((struct timer *)data)->count);
	printf("time = %d\n", ((struct timer *)data)->time);
	printf("flag = %d\n", ((struct timer *)data)->flag);
	printf("string = %s\n", (char *)(((struct timer *)data)->string));
}

void travel(void)
{
	struct node_t *tail = NULL;
	struct node_t *save_tail = NULL;

	for (tail = head.node.next; tail != &head.node; tail = save_tail)
	{
		save_tail = tail->next;

		((struct timer *)tail->data)->count++;

		if ( ((struct timer *)tail->data)->count == ((struct timer *)tail->data)->time)
		{
			p_string(tail->data);
			((struct timer *)tail->data)->count = 0;

			if (0 == ((struct timer *)tail->data)->flag)
			{
				tail->prev->next = tail->next;
				tail->next->prev = tail->prev;
				free(tail);
			}
		}

		
		// ls(tail->data);
	}

}

void destroy(void)
{
	struct node_t *tail = NULL, *save_tail = NULL;

	for (tail = head.node.next; tail != &head.node; tail = save_tail)
	{
		save_tail = tail->next;

		free(tail);
	}

	printf("destroy done!\n");
}

void time_over(int sig)
{
	travel();
}

int main(int argc, char **argv)
{
	int ret;

	printf("main start...\n");

	head_init();
	// void append(int count, int time, int flag, void *s)
	append(0, 1, 1, "11111");
	append(0, 3, 1, "33333");
	append(0, 5, 1, "55555");
	append(0, 7, 0, "77777");
	append(0, 8, 0, "88888");
	append(0, 9, 1, "99999");

	atexit(destroy);
// int setitimer(int which, const struct itimerval *new_value,
//                      struct itimerval *old_value);
//   ITIMER_REAL    decrements in real time, and delivers SIGALRM upon expiration.
//   struct itimerval {
//                struct timeval it_interval;  next value 
//                struct timeval it_value;    /* current value */
//            };

//            struct timeval {
//                time_t      tv_sec;         /* seconds */
//                suseconds_t tv_usec;        /* microseconds */
//            };

	struct itimerval tv;
	tv.it_interval.tv_sec = 1;
	tv.it_interval.tv_usec = 0;

	tv.it_value.tv_sec = 0;
	tv.it_value.tv_usec = 1;

	ret = setitimer(ITIMER_REAL, &tv, NULL);
	ERRP(-1 == ret, setitimer, goto ERR1);

	signal(SIGALRM, time_over);

	getchar();

	printf("main end...\n");

	return 0;
ERR1:
	return  -1;
}
