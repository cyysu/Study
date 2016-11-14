#include "queue_llist.h"

QUEUE_LLIST *queue_llist_create(int size, int max)
{
	QUEUE_LLIST *handle = NULL;

	handle = (QUEUE_LLIST *)malloc(sizeof(QUEUE_LLIST));
	ERRP(NULL == handle, malloc handle, goto ERR1);

	handle->front = 0;
	handle->end = 0;
	handle->size = size;
	handle->max = max;
	handle->head.data = NULL;
	handle->head.prev = &handle->head;
	handle->head.next = &handle->head;

	return handle;
ERR1:
	return NULL;
}

int queue_llist_is_full(QUEUE_LLIST *handle)
{
	if(handle->front == ((handle->end + 1) % handle->max))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void queue_llist_in(void *data, QUEUE_LLIST *handle)
{
	struct node_t *new = NULL;

	if(queue_llist_is_full(handle))
	{
		return;
	}

	ERRP(NULL == data, queue_llist_in data, goto ERR1);

	new = (struct node_t *)malloc(sizeof(struct node_t));
	ERRP(NULL == new, malloc new, goto ERR1);

	new->data = (void *)malloc(handle->size);
	ERRP(NULL == new->data, malloc new->data, goto ERR2);

	memcpy(new->data, data, handle->size);

	new->next = &handle->head;
	new->prev = handle->head.prev;
	handle->head.prev->next = new;
	handle->head.prev = new;
	handle->end ++;

	if(handle->max == handle->end)
	{
		handle->end = 0;
	}

	return;
ERR2:
	free(new);
ERR1:
	return;

}

int queue_llist_is_empty(QUEUE_LLIST *handle)
{
	if(handle->front == handle->end)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int queue_llist_len(QUEUE_LLIST *handle)
{
	if(handle->end > handle->front)
	{
		return (handle->end - handle->front);
	}
	else
	{
		return (handle->max - (handle->front - handle->end));
	}
}

void *queue_llist_out(QUEUE_LLIST *handle)
{
	struct node_t *tail = NULL;
	int i;

	if(queue_llist_is_empty(handle))
	{
		return NULL;
	}

	tail = handle->head.next;
	for(i = 0, tail = handle->head.next; i < handle->front; i++, tail = tail->next)
	{
	}

	handle->front ++;
	if(handle->front == handle->max)
	{
		handle->front = 0;
	}

	return tail->data;
}

void queue_llist_travel(QUEUE_LLIST *handle, queue_llist_op_t *op)
{
	int i;
	struct node_t *tail = NULL;

	for(i = 0, tail = handle->head.next; i < handle->front; i++, tail = tail->next)
	{
	}

	for(i = 0; i < queue_llist_len(handle); i ++, tail = tail->next)
	{
		op(tail->data);
	}
}

void queue_llist_destory(QUEUE_LLIST *handle)
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

void queue_llist_store(char *path, QUEUE_LLIST *handle)
{
	FILE *fp = NULL;
	int ret;
	int i, len =0;
	struct node_t *tail = NULL;
	fp = fopen(path, "w");
	ERRP(NULL == fp, fopen fp, goto ERR1);

	ret = fwrite(&handle->size, sizeof(handle->size), 1, fp);
	ERRP(ret != 1, fwrite handle->size, goto ERR2);

	ret = fwrite(&handle->max, sizeof(handle->max), 1, fp);
	ERRP(ret != 1, fwrite handle->max, goto ERR2);

	len = queue_llist_len(handle);

	ret = fwrite(&len, sizeof(len), 1, fp);
	ERRP(ret != 1, fwrite len, goto ERR2);

	for(i = 0, tail = handle->head.next; i < handle->front; i ++, tail = tail->next);

	for(i = 0; i < queue_llist_len(handle); i ++, tail = tail->next)
	{
		ret = fwrite(tail->data, handle->size, 1, fp);
		ERRP(ret != 1, fwrite tail->data, goto ERR2);
	}

	fclose(fp);

	return;
ERR2:
	close(fp);
ERR1:
	return;
}

QUEUE_LLIST *queue_llist_load(char *path)
{
	FILE *fp = NULL;
	int ret, i;
	int size, max, len;
	void *new = NULL;

	QUEUE_LLIST *handle = NULL;

	fp = fopen(path, "r");
	ERRP(NULL == fp, fopen fp, goto ERR1);

	ret = fread(&size, sizeof(size), 1, fp);
	ERRP(ret != 1, fread size, goto ERR2);

	ret = fread(&max, sizeof(max), 1, fp);
	ERRP(ret != 1, fread max, goto ERR2);

	ret = fread(&len, sizeof(len), 1, fp);
	ERRP(ret != 1, fread len, goto ERR2);

	handle = queue_llist_create(size, max);
	ERRP(NULL == handle, queue_llist create handle, goto ERR2);

	for(i = 0; i < len; i++)
	{
		new = (void *)malloc(size);
		ERRP(NULL == new, malloc new, goto ERR3);

		ret = fread(new, size, 1, fp);
		ERRP(ret != 1, fread ret, goto ERR3);

		queue_llist_in(new, handle);
	}

	fclose(fp);

	return handle;
ERR3:
	free(handle);
ERR2:
	close(fp);
ERR1:
	return;
}

