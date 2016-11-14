#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//有头 有序 循环 单向
//定义链表节点信息结构体类型
struct node_t{
	int data;
	struct node_t *next;
};

int main(void)
{
	int num;//表示临时保存用户数据
	struct node_t head = {0, &head};//循环链表
	struct node_t *new = NULL;//表示接受用户数据
	struct node_t *tail = NULL;//循环变量

	while(1)
	{
		printf("please input number : ");
		scanf("%d", &num);

		if (num == -1)
		{
			break;
		}

		new = (struct node_t *)malloc(sizeof(struct node_t));
		if (new == NULL)
		{
			printf("malloc failed!\n");
			return -1;
		}
		
		//表示临时接受用户数据保存链表节点信息中。
		new->data = num;

		for (tail = &head; tail->next != &head && new->data > tail->next->data; tail = tail->next)
			;
		new->next = tail->next;
		tail->next = new;


	}

	for (tail = head.next; tail != &head; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	printf("\n");

	for (tail = head.next; tail != &head; tail = new)
	{
		new = tail->next;
		free(tail);
	}
	/*printf("1st = %d\n", head.next->data);*/
	return 0;
}
