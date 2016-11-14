#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_MAX 10

struct hash_t{
	int data;
	struct hash_t *next;
};

int hash_num(int num)
{
	return num % HASH_MAX;
}

int hash_find(int key, struct hash_t * hash)
{
	int num;
	struct hash_t *tail = NULL;
	num = hash_num(key);

	for(tail = hash[num].next; tail != NULL; tail = tail->next)
	{
		if(tail->data == key)
		{
			return tail->data;
		}
	}
	return -1;
}

void hash_travel(struct hash_t * hash)
{
	int i;
	struct hash_t *tail = NULL;
	for(i = 0; i < HASH_MAX; i++)
	{
		printf("%d :", i);
		for(tail = hash[i].next; tail != NULL; tail = tail->next)
		{
			printf("%d ", tail->data);
		}
		putchar(10);
	}
}

int main(void)
{
	struct hash_t head[HASH_MAX];
	struct hash_t *new = NULL;
	struct hash_t *tail = NULL;
	int i, temp, num;
	
	memset(head, 0, sizeof(head));
	for(i = 0; i < HASH_MAX; i++)
	{
		num = rand() % 20;

		temp = hash_num(num);

		new = (struct hash_t *)malloc(sizeof(struct hash_t));
		new ->data = num;
		new ->next = NULL;

		for (tail = &head[temp]; tail->next != NULL; tail = tail->next)
			;
		tail->next = new;
	}

	hash_travel(head);

	printf("please input a num:");
	scanf("%d", &num);
	temp = hash_find(num, head);
	if(-1 == temp)
	{
		printf("%d is not find\n", num);
	}
	else
	{
		printf("%d\n", temp);
	}

	return 0;
}
