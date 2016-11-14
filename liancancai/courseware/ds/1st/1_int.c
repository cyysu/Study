#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct cls_t{
	char name[128];
	int id;
	int age;
	char sex;
	double cn;
	double en;
};

//int -> user -> save -> malloc count -> printf -> free
int main(void)
{
	int i;
	int count = 0;
	int num;//临时接受用户输入
	int *new = NULL;//用来存储用户数据所有数据
	int *prev = NULL;//用来保存原来数据

	//表示接受用户数据
	while(1)
	{
		printf("please input nunber : ");
		scanf("%d", &num);

		//退出条件
		if (num == -1)
		{
			break;
		}

		//申请数据空间
		new = (int *)malloc(sizeof(int) * (count + 1));
		if (NULL == new)
		{
			printf("malloc failed!\n");
			return -1;
		}

		//添加数据到空间地址中
		memcpy(new, prev, sizeof(int) * count);
		free(prev);
		new[count] = num;
		prev = new;

		count++;
	}

	for (i = 0; i < count; i++)
	{
		printf("%d %p | ", new[i], new + i);
	}
	printf("\n");

	free(new);
	return 0;
}
