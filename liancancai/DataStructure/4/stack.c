#include "stack.h"

STACK *stack_create(int max, int size)
{
	STACK *handle = NULL;

	handle = (STACK *)malloc(sizeof(STACK));
	ERRP(NULL == handle, malloc handle, goto ERR1);
	
	handle->data = (void *)malloc(size * max);
	handle->size = size;
	handle->top = 0;
	handle->max = max;

	return handle;
ERR1:
	return NULL;
}

int stack_isfull(STACK *handle)
{
	if(handle->top == handle->max)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int stack_isempty(STACK *handle)
{
	if(0 == handle->top)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void stack_push(void *data, STACK *handle)
{
	if(stack_isfull(handle))
	{
		return ;
	}
	ERRP(NULL == data, stack_push data, goto ERR1);
	
	memcpy(handle->data + handle->top * handle->size , data, handle->size);
	handle->top++;

ERR1:
	return;
}

void *stack_pop(STACK *handle)
{
	if(stack_isempty(handle))
	{
		return NULL;
	}
	
	handle->top --;

	return handle->data + handle->top * handle->size;
}

void stack_travel(STACK *handle, stack_op_t *op)
{
	int i;

	for(i = 0; i < handle->top; i++)
	{
		op(handle->data + handle->size * i);
	}
}

void stack_destroy(STACK *handle)
{
	free(handle->data);
	free(handle);
}