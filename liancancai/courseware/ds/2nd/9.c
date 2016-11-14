#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//有头 无序 循环 双向链表
//定义双向链表节点信息
struct node_t{
	int data;//数据域 保存用户数据数据
	struct node_t *next;//指针域 保存下一个节点地址
	struct node_t *prev;//指针域 保存上一个节点地址
};

int main(void)
{
	int num;
	struct node_t head = {0, &head, &head};//定义头节点并初始化
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

		//把新的节点信息保存到链表中,添加到链表结尾
		//next:下一个节点地址
		//prev:上一个节点地址
		//new->next	: 表示始终指向头节点
		//new->prev : 表示始终指向最后一个节点
		//head.prev->next : 表示始终指向新来节点
		//head.prev : 表示始终指向最后一个节点地址


		new->next = &head;//表示新节点next指向头节点
		new->prev = head.prev;//表示新节点prev指向原来链表最后节点地址
		head.prev->next = new;//表示原来最后一个节点next指向新节点地址
		head.prev = new;//表示头节点prev指向新节点地址
	}

	printf("next :");
	for (tail = head.next; tail != &head; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	printf("\n");
	printf("prev : ");
	for (tail = head.prev; tail != &head; tail = tail->prev)
	{
		printf("%d ", tail->data);
	}
	printf("\n");

	for (tail = head.next; tail != &head; tail = new)
	{
		new = tail->next;
		free(tail);
	}
	
	return 0;
}
