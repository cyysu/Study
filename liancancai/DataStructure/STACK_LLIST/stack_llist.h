#ifndef __STACK_LLIST_H__
#define __STACK_LLIST_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INFORMATION   do{					\
		printf("file: %s\n", __FILE__);		\
		printf("func: %s\n", __func__);		\
		printf("line: %d\n", __LINE__);		\
}while(0)

#define ERRP(condition, string, ret) do{	\
		if(condition)						\
		{									\
			printf(#string" failen\n");		\
			INFORMATION;					\
			ret;							\
		}									\
}while(0)



struct node_t
{
	void *data;
	struct node_t *next;
	struct node_t *prev;
};

typedef struct stack_t{
	int top;
	int size;
	int max;
	struct node_t head; 
}STACK;

typedef void(stack_llist_op_t)(void *);

STACK *stack_llist_create(int size, int max);
void stack_llist_push(void *data, STACK * handle);
void *stack_llist_pop(STACK *handle);

int stack_llist_is_full(STACK *handle);
int stack_llist_is_empty(STACK *handle);

void stack_llist_destroy(STACK *handle);
void stack_llist_store(char *path, STACK *handle);
STACK *stack_llist_load(char *path);
void stack_llist_travel(STACK *handle, stack_llist_op_t *op);

#endif /*stack_llist.h*/