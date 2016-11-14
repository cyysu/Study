#ifndef __QUEUE_LLIST_H__
#define __QUEUE_LLIST_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUEUE_LLIST_MAX 15

#define INFORMATION   do{					\
		printf("file: %s\n", __FILE__);		\
		printf("func: %s\n", __func__);		\
		printf("line: %d\n", __LINE__);		\
}while(0)

#define ERRP(condition, string, ret) do{	\
		if(condition)						\
		{									\
			printf(#string" failed\n");		\
			INFORMATION;					\
			ret;							\
		}									\
}while(0)

struct node_t{
	struct node_t *prev;
	struct node_t *next;
	void *data;
};

typedef struct queue_llist_t{
	int front;
	int end;
	int size;
	int max;
	struct node_t head;
}QUEUE_LLIST;

typedef void (queue_llist_op_t) (void *);

QUEUE_LLIST *queue_llist_create(int size, int max);
int queue_llist_is_full(QUEUE_LLIST *handle);
void queue_llist_in(void *data, QUEUE_LLIST *handle);
int queue_llist_is_empty(QUEUE_LLIST *handle);
int queue_llist_len(QUEUE_LLIST *handle);
void *queue_llist_out(QUEUE_LLIST *handle);
void queue_llist_travel(QUEUE_LLIST *handle, queue_llist_op_t *op);
void queue_llist_destory(QUEUE_LLIST *handle);
void queue_llist_store(char *path, QUEUE_LLIST *handle);
QUEUE_LLIST *queue_llist_load(char *path);

#endif