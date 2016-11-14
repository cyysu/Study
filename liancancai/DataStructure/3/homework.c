#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node_t{
	int data;
	struct node_t *next;
	struct node_t *prev;
};

int main(void)
{
	struct node_t *head = NULL;
	struct node_t *new  = NULL;
	struct node_t *tail = NULL;
	struct node_t *save = NULL;
	int num = 0;
	int i;
	int dith_num = 0;
	printf("请输入人数:");	
	scanf("%d", &num);

	printf("请输入死亡号码：");
	scanf("%d", &dith_num);

	for(i = 0; i< num ; i++)
	{
		new = (struct node_t *)malloc(sizeof(struct node_t));

		new->data = i + 1;

		if(NULL == head)
		{
			head = new;
			head->next = head;
			head->prev = head;
		}
		else
		{
			new->next = head;
			new->prev = head->prev;
			head->prev->next = new;
			head->prev = new;
		}
	}

	// for(tail = head; tail->next != head; tail = tail->next)
	// {
	// 	printf("%d ", tail->data);
	// }
	// printf("%d ", tail->data);
	tail = head;
	i = 1;
	while(num)
	{
		if(dith_num != i)
		{
			printf("%3d%3d\n",tail->data, i);
		}
		else
		{
			printf("\033[32m%3d\033[0m%3d\n",tail->data, i);
			save = tail->next;
			tail->prev->next = tail->next;
			tail->next->prev = tail->prev;
			num --;
			i = 0;
			free(tail);
			tail = save->prev;
		}
		tail = tail->next;
		i++;
	}


	putchar(10);

}