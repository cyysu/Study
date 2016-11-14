#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//无头 有序 循环 单向
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
			if (new->data < head->data)
			{
				new->next = head;
				for (tail = head; tail->next != head; tail = tail->next)
					;
				tail->next = new;
				head = new;
			}
			else
			{
				for (tail = head; tail->next != head && new->data > tail->next->data; tail = tail->next)
					;
				new->next = tail->next;
				tail->next = new;
			}
		}

	}

	for (tail = head; tail->next != head; tail = tail->next)
	{
		printf("%d ", tail->data);
	}
	printf("%d\n", tail->data);
	return 0;
}
