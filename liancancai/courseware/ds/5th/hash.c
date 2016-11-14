#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

struct hash_t{
	int data;
	struct hash_t *next;
};

//哈希算法
int hash(int num)
{
	return num % MAX;
}
int hash_find(int key, struct hash_t *head)
{
	int num = hash(key);
	struct hash_t *tail = NULL;

	for (tail = head[num].next; tail != NULL; tail = tail->next)
	{
		if (key == tail->data)
		{
			return tail->data;
		}
	}
	return -1;
}
int main(void)
{
	int i, num, tmp;
	struct hash_t head[MAX];
	struct hash_t *tail = NULL, *new = NULL;

	memset(head, 0, sizeof(head));

	srand(time(NULL));
	//创建哈希表
	for (i = 0; i < MAX; i++)
	{
		num = rand() % 100;

		new = (struct hash_t *)malloc(sizeof(struct hash_t));
		if (new == NULL)
		{
			return -1;
		}

		new->data = num;
		new->next = NULL;

		tmp = hash(num);

		for (tail = &head[tmp]; tail->next != NULL; tail = tail->next)
			;

		tail->next = new;


	}
    /*
	 *int key, ind;
	 *printf("please input find key : ");
	 *scanf("%d", &key);
	 *ind  = hash_find(key, head);
	 *if (ind == -1)
	 *{
	 *    printf("no find!\n");
	 *}
	 *else
	 *{
	 *    printf("ind = %d\n", ind);
	 *}
     */
	

	//哈希遍历
	for (i = 0; i < MAX; i++)
	{
		printf("%d : ", i);
		for (tail = head[i].next; tail != NULL; tail = tail->next)
		{
			printf("%d ", tail->data);
		}
		printf("\n");
	}

	//哈希销毁
	for (i = 0; i < MAX; i++)
	{
		printf("%d : ", i);
		for (tail = head[i].next; tail != NULL; tail = new)
		{
			new = tail->next;
			free(tail);
		}
		printf("\n");
	}
	
	return 0;
}




