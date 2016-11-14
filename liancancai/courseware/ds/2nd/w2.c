#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//实现约瑟夫环 无头 无序 循环 双向链表

struct node_t{
	char *name;
	struct node_t *next;
	struct node_t *prev;
};

int main(void)
{
	int m, n, i;
	char buf[128];
	struct node_t *head = NULL;//表示无头
	struct node_t *new = NULL;
	struct node_t *tail = NULL;
	int count = 0;

	printf("please input m and n : ");
	scanf("%d%d", &m, &n);
	getchar();

	for (i = 0; i < m; i++)
	{
		printf("please input %d name : ", i + 1);
		fgets(buf, sizeof(buf), stdin);
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0';

		new = (struct node_t *)malloc(sizeof(struct node_t));
		if (new == NULL)
		{
			return -1;
		}
		new->name = (char *)malloc(strlen(buf) + 1);
		if (new->name == NULL)
		{
			free(new);
			return -1;
		}

		strcpy(new->name, buf);

		//尾插
		if (head == NULL)
		{
			new->next = new;
			new->prev = new;
			head = new;
		}
		else
		{
			new->next = head;
			new->prev = head->prev;
			head->prev->next = new;
			head->prev = new;
		}
	}

	for (tail = head; tail->next != head; tail = tail->next)
	{
		printf("%s ", tail->name);
	}
	printf("%s\n", tail->name);


	tail = head;

	while(tail->next != tail)
	{
		count++;
		new = tail->next;
		if (count == n)
		{
			printf("%s ", tail->name);
			tail->next->prev = tail->prev;
			tail->prev->next = tail->next;
			free(tail->name);
			free(tail);
			count = 0;
		}
		tail = new;
	}
	printf("%s\n", tail->name);

	return 0;
}
