#include "stack_llist.h"

// struct node_t
// {
// 	void *data;
// 	node_t *next;
// 	node_t *prev;
// }

// struct stack_t{
// 	int top;
// 	int size;
// 	int max;
// 	struct node_t head; 
// }STACK;

STACK *stack_llist_create(int size, int max)
{
	STACK *handle = NULL;

	handle = (STACK *)malloc(sizeof(STACK));
	ERRP(NULL == handle, malloc handle, goto ERR1);

	handle->top = 0;
	handle->size = size;
	handle->max = max;
	handle->head.next = &handle->head;
	handle->head.prev = &handle->head;
	handle->head.data = NULL;

	return handle;
ERR1:
	return NULL;
}

int stack_llist_is_full(STACK *handle)
{
	// printf("handle->max = %d\n", handle->max);
	if(handle->top == handle->max)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int stack_llist_is_empty(STACK *handle)
{
	if(handle->top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void stack_llist_push(void *data, STACK * handle)
{
	struct node_t *new = NULL;
	if(stack_llist_is_full(handle))
	{
		// printf("full\n");
		return;
	}

	ERRP(NULL == data, stack_llist_push, goto ERR1);

	new = (struct node_t *)malloc(sizeof(struct node_t));
	ERRP(NULL == new, malloc new, goto ERR1);

	new->data = (void *)malloc(handle->size);
	ERRP(NULL == new->data, malloc new->data, goto ERR2);

	memcpy(new->data, data, handle->size);

	new->next = &handle->head;
	new->prev = handle->head.prev;
	handle->head.prev->next = new;
	handle->head.prev = new;
	handle->top ++;
	// printf("top = %d\n", handle->top);

	return ;
ERR2:
	free(new);
ERR1:
	return;
}

void *stack_llist_pop(STACK *handle)//这里不清楚返回类型
{
	int i = 0;
	struct node_t *tail = NULL;
	struct node_t *save = NULL;
	if(stack_llist_is_empty(handle))
	{
		return ;
	}
	
	tail = handle->head.next;

	handle->top --;

	for(i = 0; i < handle->top; i++)
	{
		tail = tail->next;
	}

	save = tail;
	free(tail);
	return(save->data);
	// return (handle->)
}

void stack_llist_travel(STACK *handle, stack_llist_op_t *op)
{
	struct node_t *tail = NULL;
	int i;
	for(tail = handle->head.next, i = 0; tail != &handle->head && i < handle->top; tail = tail->next, i++)
	{
		op(tail->data);
	}
}

void stack_llist_destroy(STACK *handle)
{
	struct node_t *tail = NULL;
	struct node_t *save = NULL;

	for(tail = handle->head.next; tail != &handle->head; tail = save)
	{
		save = tail->next;
		free(tail);
	}

	free(handle);
}

void stack_llist_store(char *path, STACK *handle)
{
	FILE *fp = NULL;
	int ret, i;
	struct node_t *tail = NULL;

	fp = fopen(path, "w");
	ERRP(NULL == fp, fopen fp, goto ERR1);


	ret = fwrite(&handle->top, sizeof(handle->top), 1, fp);
	ERRP(ret != 1, fwrite handle->top, goto ERR2);

	ret = fwrite(&handle->size, sizeof(handle->size), 1, fp);
	ERRP(ret != 1, fwrite handle->size, goto ERR2);

	ret = fwrite(&handle->max, sizeof(handle->max), 1, fp);
	ERRP(ret != 1, fwrite handle->max, goto ERR2);
	printf("top = %d, size = %d, max = %d\n", handle->top, handle->size, handle->max);

	tail = handle->head.next;

	for( i = 0; i < handle->top; i++)
	{
		ret = fwrite(tail->data, handle->size, 1, fp);
		ERRP(ret != 1, fwrite tail->data, goto ERR2);

		tail = tail->next;
	}

	close(fp);
	return;
ERR2:
	close(fp);
ERR1:
	return;
}

STACK  *stack_llist_load(char *path)
{
	FILE *fp = NULL;
	int ret, i, top, size, max;
	STACK *handle = NULL;
	void *data = NULL;
	printf("d\n");

	fp = fopen(path, "r");
	ERRP(NULL == fp, fopen fp, goto ERR1);

	ret = fread(&top, sizeof(top), 1, fp);
	ERRP(ret != 1, fread top, goto ERR2);

	ret = fread(&size, sizeof(size), 1, fp);
	ERRP(ret != 1, fread size, goto ERR2);

	ret = fread(&max, sizeof(max), 1, fp);
	ERRP(ret != 1, fread max , goto ERR2);

	handle = stack_llist_create(size, max);
	printf("top = %d, size = %d, max = %d\n", top, size, max);
	for(i = 0; i < top; i++)
	{
		data = (void *)malloc(size);
		ERRP(NULL == data, malloc data, goto ERR3);

		ret = fread(data, size, 1, fp);
		ERRP(ret != 1, fread data , goto ERR3);

		stack_llist_push(data, handle);
	}

	fclose(fp);

	return handle;
ERR3:
	free(handle);	
ERR2:
	fclose(fp);
ERR1:
	return NULL;
}
