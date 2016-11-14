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


int main(int argc, char **argv)
{
	int i, j;
	int ret;
	int count = 0;

	for (i = 3000; i < 6000; i++)
	{
		if ( i % 300 == 0 )
		{
			//这里要单独判断 6000
			for (j = 1; j <= 6000; j++)
			{
				if (6000 % j == 0 && j != 6000 && j != 1)
				{
					break;
				}

				if (6000 == j)
				{
					count ++;
				}
			}

			ret = fork();

			if (0 != ret)//parents
			{
				int j, k;

				for (j = i ; j < i + 300; j++)//素数的判断
				{
					for (k = 1; k <= j; k++)
					{
						if (j % k == 0 && j != k && k != 1)
						{
							break;
						}

						if (j == k)
						{
							count ++;

							//打印素数
							// printf("%d\n", j);
						}
					}
				}
				if (6000 == j)
				{
					printf("count = %d\n", count);
				}
			}
			else//child
			{
				exit(0);
			}
		}
	}

	return 0;
ERR1:
	return 0;

}
