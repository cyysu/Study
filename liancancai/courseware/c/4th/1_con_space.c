#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a;

	/*srand(time(NULL));*/
	srand(getpid());

	printf("getpid = %d\n", getpid());
	getchar();
    /*
	 *while(1)
	 *{
	 *    printf("time(NULL) = %d\n", time(NULL));
	 *    sleep(1);
	 *}
     */
	printf("rand = %d\n", rand() % 100);
	if (a = 123)
	{
		printf("hello!\n");
	}
	return 0;
}
