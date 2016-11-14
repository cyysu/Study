#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//无头 有序 循环 双向链表
//定义双向链表节点信息
struct node_t{
	int data;//数据域 保存用户数据数据
	struct node_t *next;//指针域 保存下一个节点地址
	struct node_t *prev;//指针域 保存上一个节点地址
};

int main(void)
{
	int num;
	struct node_t *head = NULL;//定义头节点并初始化
	struct node_t *new = NULL;
	struct node_t *tail = NULL;
	
	//死循环接受用户输入
	while(1)
	{
		//接受用户数据，并保存到临时变量中。
		printf("please input number : ");
		scanf("%d", &num);

		//退出条件
		if (num == -1)
		{
			break;
		}

		//给新来的数据分配一个节点地址空间。
		new = (struct node_t *)malloc(sizeof(struct node_t));
		if (new == NULL)
		{
			return -1;
		}

		//保存数据到节点信息中 数据节点是独立的
		new->data = num;
		new->next = NULL;
		new->prev = NULL;

		if (head == NULL)
		{
			new->next = new;
			new->prev = new;
			head = new;
		}
		else
		{
			if (new->data < head->data)
			{
				new->next = head;
				new->prev = head->prev;
				head->prev->next = new;
				head->prev = new;
				head = new;
			}
			else
			{
				for (tail = head; tail->next != head; tail = tail->next)
				{
					if (new->data < tail->next->data)
						break;
				}
				new->next = tail->next;
				new->prev = tail;
				tail->next->prev = new;
				tail->next = new;
			}
		}


	}

	printf("next :");
	for (tail = head; tail->next != head; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	printf("%d\n", tail->data);
	printf("prev : ");
	for (tail = head->prev; tail != head; tail = tail->prev)
	{
		printf("%d ", tail->data);
	}
	printf("%d\n", tail->data);

	for (tail = head; tail->next != head; tail = new)
	{
		new = tail->next;
		free(tail);
	}
	
	return 0;
}
