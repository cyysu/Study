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

void stack_store(char *path, STACK *handle)
{
	FILE *fp = NULL;
	int ret;
	fp = fopen(path, "w");
	ERRP(NULL == fp, fopen fp, goto ERR1);
	int i;

	ret = fwrite(&handle->size, sizeof(handle->size), 1, fp);
	ERRP(ret != 1, fwrite handle->size, goto ERR2);

	ret = fwrite(&handle->max, sizeof(handle->max), 1, fp);
	ERRP(ret != 1, fwrite handle->max, goto ERR2);

	ret = fwrite(&handle->top, sizeof(handle->top), 1, fp);
	ERRP(ret != 1, fwrite handle->top, goto ERR2);

	for(i = 0; i < handle->top; i++)
	{
		ret = fwrite(handle->data + handle->size * i, handle->size, 1, fp);
		ERRP(ret != 1, fwrite handle->data, goto ERR2);
	}
	
	fclose(fp);
	
	return;
ERR2:
	fclose(fp);
ERR1:
	return ;
}

STACK *stack_load(char *path)//size -> max
{
	FILE *fp = NULL;
	STACK *handle = NULL;
	int size ;
	int max ;
	int top ;
	int ret;
	int i;
	void *data = NULL;


	fp = fopen(path, "r");
	ERRP(NULL == fp, fopen fp, goto ERR1);

	handle = (STACK *)malloc(sizeof(STACK));
	ERRP(NULL == handle, malloc handle, goto ERR2);

	ret = fread(&size, sizeof(size), 1, fp);
	ERRP(ret != 1, fread size, goto ERR3);

	ret = fread(&max, sizeof(max), 1, fp);
	ERRP(ret != 1, fread max, goto ERR3);

	ret = fread(&top, sizeof(top), 1, fp);
	ERRP(ret != 1, fread top, goto ERR3);

	handle = stack_create(max, size);

	for(i = 0; i < top; i ++)
	{
		data = (void *)malloc(size);
		ERRP(NULL == data, malloc data, goto ERR3);

		ret = fread(data, size, 1, fp);
	
		ERRP(ret != 1, fread handle->data, goto ERR4);

		stack_push(data, handle);
	}


	fclose(fp);
	return handle;
ERR4:
	free(data);
ERR3:
	free(handle);
ERR2:
	fclose(fp);
ERR1:
	return NULL;
}
