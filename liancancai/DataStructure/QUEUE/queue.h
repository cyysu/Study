#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define QUEUE_MAX 30

#define INFORMATION do{				\
	printf("file :%s", __FILE__);	\
	printf("func :%s", __func__);	\
	printf("line :%d", __LINE__);	\
}while(0)


#define ERRP(condition, string, ret) do{	\
	if(condition)							\
	{										\
		printf(#string" failed\n");			\
		INFORMATION;						\
		ret;								\
	}										\
}while(0)


typedef struct queue_t{
	void *data;
	int front;
	int end;
	int size;
	int max;
}QUEUE;

typedef void (queue_op_t)(void *);

QUEUE *queue_create(int max, int size);
void queue_in(void *data, QUEUE *handle);
void *queue_out(QUEUE *handle);
void queue_travel(QUEUE *queue, queue_op_t *op);
int queue_is_full(QUEUE *handle);
void *queue_out(QUEUE *handle);
int queue_is_empty(QUEUE *handle);
int queue_len(QUEUE *handle);
void queue_destory(QUEUE *handle);
void queue_store(char *path, QUEUE *handle);
QUEUE *queue_load(char *path);

#endif