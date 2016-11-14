#include "select_course_simple.h"


LLIST *llist_create(int size)
{
	LLIST *handle = NULL;

	handle = (LLIST *)malloc(sizeof(LLIST));
	ERRP(NULL == handle, malloc handle, goto ERR1);

	handle->size = size;
	handle->num = 0;
	handle->head.next = &handle->head;
	handle->head.prev = &handle->head;
	handle->head.data = NULL;

	return handle;

ERR1:
	return NULL;
}

void llist_add(void *data, LLIST *handle)
{
	struct node_t *new = NULL;

	new = (struct node_t *)malloc(sizeof(struct node_t));
	ERRP(NULL == new, malloc new, goto ERR1);

	new->data = (void *)malloc(handle->size);
	ERRP(NULL == new->data, malloc new->data, goto ERR2);

	memcpy(new->data, data, handle->size);

	new->next = &handle->head;
	new->prev = handle->head.prev;
	handle->head.prev->next = new;
	handle->head.prev = new;

	return;
ERR2:
	free(new);
ERR1:
	return;
}

void llist_travel(LLIST *handle, llist_op_t *op)
{
	struct node_t *tail = NULL;
	int i;

	for(tail = handle->head.next, i = 0; tail != NULL; tail = tail->next, i++);
	{
		op(tail->data + handle->size * i);
	}
}