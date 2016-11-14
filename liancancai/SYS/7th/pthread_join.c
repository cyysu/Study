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
#include <pthread.h>



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

void *hello(void *data)
{
	int *p = NULL;
	printf("count = %d\n", *(int *)data);

	*(int *)data = 1111;

	p = (int *)malloc(sizeof(int));

	*p = 2222;

	pthread_exit(p);

}

struct cls_t{
	char name[128];
	int age;
	char sex;
	double  grade;
};

void *cls(void *data)
{
	printf("name = %s\n", ((struct cls_t*)data)->name);
	printf("age = %d\n", ((struct cls_t*)data)->age);
	printf("sex = %c\n", ((struct cls_t*)data)->sex);
	printf("grade = %lf\n", ((struct cls_t*)data)->grade);

	((struct cls_t*)data)->age = 99;

	pthread_exit(data);
}

int main(int argc, char **argv)
{
	pthread_t pthread;
	int ret, count = 0;
	struct cls_t stu = {"lcc", 20, 'M', 60.5};

	struct cls_t *p = NULL;

	ret = pthread_create(&pthread, NULL, cls, &stu);
	ERRP(ret != 0, pthread_create, goto ERR1);

	pthread_join(pthread, (void **)&p);

	// printf("count = %d\n", count);

	printf("p->age = %d\n", p->age);

	return 0;
ERR1:
	return -1;
}
