#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//无头 无序 循环 单向
struct node_t{
	int data;
	struct node_t *next;
};

int main(void)
{
	int num;
	struct node_t *head = NULL;
	struct node_t *new = NULL, *tail = NULL;

	while(1)
	{
		printf("Enter numbers : ");
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

		if (head == NULL)
		{
			new->next = new;
			head = new;
		}
		else
		{
			for (tail = head; tail->next != head; tail = tail->next)
				;
			new->next = head;
			tail->next = new;
		}

	}

	for (tail = head; tail->next != head; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	printf("%d\n", tail->data);
	return 0;
}
