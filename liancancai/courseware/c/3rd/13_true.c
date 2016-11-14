#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int count = 0;

	while (1)
	{
		if (count == 5)
		{
			/*return -1;*/
			/*break;*/
			continue;
		}
		printf("world");//行缓冲函数
		count++;
		/*puts("hello");*/
		sleep(1);//表示延迟1秒
		/*fflush(stdout);//表示输出缓冲区*/
		fflush(NULL);//表示刷新所有缓冲区
		/*printf("hello");*/
		/*usleep(1000000);//表示延迟0.1秒*/
	}

	printf("main end!\n");
	return 0;
}
