#include "stack.h"

STACK *stack_create(int max, int size)
{
	STACK *handle = NULL;

	handle = (STACK *)malloc(sizeof(STACK));
	ERRP(NULL == handle, malloc, goto ERR1);

	handle->data = (void *)malloc(size * max);
	ERRP(NULL == handle->data, malloc data, goto ERR2);

	handle->max = max;
	handle->size = size;
	handle->top = 0;

	return handle;
ERR2:
	free(handle);
ERR1:
	return NULL;
}

int stack_is_full(STACK *handle)
{
	if (handle->top == handle->max)
		return 1;
	return 0;
}

int stack_is_empty(STACK *handle)
{
	if (handle->top == 0)
		return 1;
	return 0;
}

void stack_push(void *data, STACK *handle)
{
	if (stack_is_full(handle))
		return ;
	memcpy(handle->data + handle->top * handle->size, data, handle->size);
	handle->top++;

}

void *stack_pop(STACK *handle)
{
	if (stack_is_empty(handle))
		return NULL;
	handle->top--;
	return handle->data + handle->top * handle->size;
}

void stack_travel(STACK *handle, stack_op_t op)
{
	int i;
	for (i = 0; i < handle->top; i++)
	{
		op(handle->data + i * handle->size);
	}
}
void stack_destroy(STACK *handle)
{
	free(handle->data);
	free(handle);
}
