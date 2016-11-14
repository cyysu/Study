#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//实现有头 无序 不循环 单向链表

struct node_t{
	int data;
	struct node_t *next;
};

int main(void)
{
	int num;
	struct node_t head = {0, NULL};//定义头节点
	struct node_t *new = NULL;
	struct node_t *tail = NULL;
	struct node_t *save = NULL, *prev = NULL;
	while(1)
	{
		printf("please input number : ");
		scanf("%d", &num);

		if (num == -1)
		{
			break;
		}

		new = (struct node_t *)malloc(sizeof(struct node_t));
		if (NULL == new)
		{
			return -1;
		}

		new->data = num;
		new->next = NULL;

		for (tail = &head; tail->next != NULL; tail = tail->next)
			;

		tail->next = new;
	}

	for (tail = head.next; tail != NULL; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	printf("\n");

	tail = head.next;
	while(tail != NULL)
	{
		save = tail->next;//保存下一个节点地址
		
		tail->next = prev;//让tail->next指向上一个节点地址
		prev = tail;//让prev重新指向上一个节点

		tail = save;//表示让tail从新指向下一个节点
	}

	head.next = prev;
	for (tail = head.next; tail != NULL; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	printf("\n");

	for (tail = head.next; tail != NULL; tail = new)
	{
		new = tail->next;
		free(tail);
	}
	return 0;
}
