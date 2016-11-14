#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30


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



typedef struct stack_t{
	void *data;
	int size;
	int top;
	int max;
}STACK;


typedef void (stack_op_t)(void *);

STACK *stack_create(int max, int size);

int stack_isfull(STACK *handle);
int stack_isempty(STACK *handle);

void stack_push(void *data, STACK *handle);
void stack_pop(STACK *handle);
void stack_travel(STACK *handle, stack_op_t *op);
void stack_destroy(STACK *handle);

void stack_store(char *path, STACK *handle);
STACK *stack_load(char *path);


#endif