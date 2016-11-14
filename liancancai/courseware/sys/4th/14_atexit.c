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


void free_a(void)
{
	printf("free_a\n");
}
void free_b(void)
{
	printf("free_b\n");
}
void free_c(void)
{
	printf("free_c\n");
}

void hello(void)
{
	printf("free hello!\n");
}
int main(int argc, char **argv)
{
	int *a = NULL;
	int *b = NULL;
	int *c = NULL;

	a = (int *)malloc(sizeof(int));
	b = (int *)malloc(sizeof(int));
	c = (int *)malloc(sizeof(int));

	printf("hello_1!\n");
	/*free(a);*/
	//注册
	atexit(free_a);
	printf("hello_2!\n");
	atexit(free_b);
	printf("hello_3!\n");
	atexit(free_c);

	printf("hello_4!\n");
	/**a = 12;*/

    /*
	 *atexit(hello);	
	 *printf("hello!\n");	
     */

    /*
	 *free(a);
	 *free(b);
	 *free(c);
     */


	return 0;
}
