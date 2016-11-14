#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//有头 有序 不循环 单向
//定义链表节点信息结构体类型
struct node_t{
	int data;
	struct node_t *next;
};

int main(void)
{
	int num;//表示临时保存用户数据
	struct node_t head = {0, NULL};//定义头节点
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
		/*new->next = NULL;*/

		for (tail = &head; tail->next != NULL && num < tail->next->data; tail = tail->next)
			;
        /*
		 *for (tail = &head; tail->next != NULL; tail = tail->next)
		 *{
		 *    if (num < tail->next->data)
		 *        break;
		 *}
         */
		//表示新来数据插入到原来最后一个节点后面
		new->next = tail->next;
		tail->next = new;


	}

	//遍历
	for (tail = head.next; tail != NULL; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	printf("\n");
	//销毁
	for (tail = head.next; tail != NULL; tail = new)
	{
		new = tail->next;
		free(tail);
	}
	/*printf("1st = %d\n", head.next->data);*/
	return 0;
}
