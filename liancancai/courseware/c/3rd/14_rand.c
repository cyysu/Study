#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num;
	int i;

	srand(time(NULL));
	for (i = 0; i < 7; i++)
	{
		if (i == 6)
		{
			printf("+ \033[31m%d\033[0m", rand() % 32 + 1);
		}
		else
		{
			printf("%d ", rand() % 32 + 1);
		}
	}
	printf("\n");

    /*
	 *
	 *while (1)
	 *{
	 *    printf("%d ", rand() % 100);
	 *    usleep(200000);
	 *    fflush(NULL);
	 *}
     */
	return 0;
}
