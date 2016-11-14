#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//无头 无序 不循环 单向

struct node_t{
	int data;
	struct node_t *next;
};

int main(void)
{
	struct node_t *head = NULL;//表示定义无头节点信息
	int num;
	struct node_t *new = NULL;
	struct node_t *tail = NULL;

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
			printf("malloc new failed!\n");
			return -1;
		}

		new->data = num;
		new->next = NULL;

		if (head == NULL)
		{
			head = new;
		}
		else
		{
			for (tail = head; tail->next != NULL; tail = tail->next)
				;
			tail->next = new;
		}
	}

	for (tail = head; tail != NULL; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	putchar(10);
	for (tail = head; tail != NULL; tail = new)
	{
		new = tail->next;
		free(tail);
	}

	return 0;
}
