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
	printf("hello\n");
}

int main(int argc, char **argv)
{
	pthread_t pthread_id;
	int ret;
	  // int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
   //                        void *(*start_routine) (void *), void *arg);
	ret = pthread_create(&pthread_id, NULL, hello, NULL);
	ERRP(ret != 0, pthread_create, goto ERR1);

	sleep(1);
	printf("pthread_id = %lu\n", pthread_id);

	printf("pthread_id = %lu\n", pthread_self());
	return 0;
ERR1:
	return -1;
}

