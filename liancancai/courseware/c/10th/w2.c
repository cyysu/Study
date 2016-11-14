#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//实现动态数组 空间不足和空间浪费 int malloc
int main(void)
{
	int i;//循环变量
	int num;//临时接受用户数据
	int count = 0;//统计用户数据数据个数
	int *new = NULL;//新的空间地址
	int *prev = NULL;//上次空间地址

	while(1)
	{
		printf("please input %d number : ", count + 1);
		scanf("%d", &num);

		//退出条件
		if (num == -1)
		{
			break;
		}

		new = (int *)malloc(sizeof(int) * (count + 1));
		if (new == NULL)
		{
			printf("malloc failed!\n");
			return -1;
		}

		#if 0
		//把数据添加到结尾
		memcpy(new, prev, sizeof(int) * count);//拷贝上次数据
		memcpy(new + count, &num, sizeof(int));
		#else
		//新的数据添加到开头
		memcpy(new, &num, sizeof(int));
		memcpy(new + 1, prev, sizeof(int) * count);
		#endif
		/*new[count] = num;//添加新来的数据*/
		free(prev);//释放上次空间
		prev = new;//重新指向新的空间地址

		/*printf("num = %d\n",  num);*/
		count++;
	}

	for (i = 0; i < count; i++)
	{
		printf("%d ", new[i]);
	}
	printf("\n");
	
	free(new);
	return 0;
}
