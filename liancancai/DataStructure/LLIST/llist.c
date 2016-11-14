#include "llist.h"


LLIST * llist_create(int size)
{
	LLIST *handle = NULL;

	handle = (LLIST *)malloc(sizeof(LLIST));
	MALLOC_ERR(NULL == handle, mallco handle, goto ERR1);

	handle->num = 0;
	handle->size = size;
	handle->head.data = NULL;
	handle->head.next = &handle->head;
	handle->head.prev = &handle->head;

	return handle;
ERR1:
	return NULL;
}

int llist_append(void *data, LLIST *handle)
{
	struct node_t *new = NULL;

	new = (struct node_t *)malloc(sizeof(struct node_t));

	MALLOC_ERR(NULL == new, malloc new, goto ERR1);

	new->data =(void *)malloc(handle->size);

	MALLOC_ERR(NULL == new->data, malloc new->data, goto ERR2);

	memcpy(new->data, data, handle->size);

	new->next = &handle->head;
	new->prev = handle->head.prev;
	handle->head.prev->next = new;
	handle->head.prev = new;
	handle->num ++;

	return 0;
ERR2:
	free(new);
ERR1:
	return -1;
}

int llist_travel(LLIST *handle, llist_op_t op, int flag)
{
	struct node_t *tail = NULL;

	if(1 == flag)
	{
		for(tail = handle->head.next; tail != &handle->head; tail = tail->next)
		{
			op(tail->data);
		}
	}
	else
	{
		for(tail = handle->head.prev; tail != &handle->head; tail = tail->prev)
		{
			op(tail->data);
		}
	}

	return 0;
}

void llist_write(char *path, LLIST *handle)
{
	FILE * fp = NULL;
	int ret;
	struct node_t *tail = NULL;

	fp = fopen(path, "w");
	MALLOC_ERR(NULL == fp, fopen fp, goto ERR1);
 // size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream);
	ret = fwrite(&handle->num, sizeof(handle->num), 1, fp);
	MALLOC_ERR(ret != 1, fwrite handle->num, goto ERR2);

	ret = fwrite(&handle->size, sizeof(handle->size), 1, fp);
	MALLOC_ERR(ret != 1, fwrite handle->size, goto ERR2);

	for(tail = handle->head.next; tail != &handle->head; tail = tail->next)
	{
		ret = fwrite(tail->data, handle->size, 1, fp);
		MALLOC_ERR(ret != 1, fwrite handle->data, goto ERR2);
	}

	fclose(fp);
	return ;
ERR2:
	fclose(fp);
ERR1:
	return;
}

LLIST  *llist_read(char *path)
{
	FILE *fp = NULL;
	int size = 0;
	int num = 0;
	int ret = 0;
	LLIST *handle = NULL;
	void *new = NULL;
	int i;

	fp = fopen(path, "r");
	MALLOC_ERR(NULL == fp, fopen fp, goto ERR1);

	ret = fread(&num, sizeof(num), 1, fp);
	MALLOC_ERR(ret != 1, fread num, goto ERR2);

	ret = fread(&size, sizeof(size), 1, fp);
	MALLOC_ERR(ret != 1, fread size, goto ERR2);

	handle = llist_create(size);
	MALLOC_ERR(NULL == handle, llist_create handle, goto ERR2);

	new = (void *)malloc(size);
	MALLOC_ERR(NULL == new, malloc new, goto ERR3);

	while(num --)
	{
		ret = fread(new, size, 1, fp);
		MALLOC_ERR(ret != 1, fread new, goto ERR4);

		llist_append(new, handle);
	}

	fclose(fp);

	return handle;
ERR4:
	free(new);	
ERR3:
	free(handle);	
ERR2:
	fclose(fp);
ERR1:
	return ;


}