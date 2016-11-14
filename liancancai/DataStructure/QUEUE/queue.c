#include "queue.h"


QUEUE *queue_create(int max, int size)
{
	QUEUE *handle = NULL;

	handle = (QUEUE *)malloc(sizeof(QUEUE));
	ERRP(NULL == handle, malloc handle, goto ERR1);

	handle->data = (void *)malloc(size * max);
	handle->front = 0;
	handle->end = 0;
	handle->size = size;
	handle->max = max;

	return handle;
ERR1:
	return NULL;
}

int queue_is_full(QUEUE *handle)
{
	if((handle->end + 1) % handle->max == handle->front)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
void queue_in(void *data, QUEUE *handle)
{
	if(queue_is_full(handle))
	{
		return;
	}

	memcpy(handle->data + handle->end * handle->size, data, handle->size);
	handle->end ++;
	if(handle->end == handle->max)
	{
		handle->end = 0;
	}
}

int queue_is_empty(QUEUE *handle)
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

void *queue_out(QUEUE *handle)
{
	void *data = NULL;

	if(queue_is_empty(handle))
	{
		printf("is empty\n");
		return NULL;
	}

	data = handle->data + handle->front * handle->size;

	handle->front ++;
	if(handle->front == handle->max)
	{
		handle->front = 0;
	}

	return data;
}

int queue_len(QUEUE *handle)
{
	if(handle->end > handle->front)
	{
		return handle->end - handle->front;
	}
	else
	{
		return (handle->max - (handle->front - handle->end));
	}
}

void queue_travel(QUEUE *handle, queue_op_t *op)
{
	int i;
	int j;
	for(i = 0, j = handle->front; i < queue_len(handle); i++, j++)
	{
		op(handle->data + handle->size * j);

		if(j == handle->max)
		{
			j = 0;
		}
	}
}

void queue_store(char *path, QUEUE *handle)
{
	FILE *fp = NULL;
	int ret;
	int i, j;
	fp = fopen(path, "w");
	ERRP(NULL == fp, fopen fp, goto ERR1);

	ret = fwrite(&handle->front, sizeof(handle->front), 1, fp);
	ERRP(ret != 1, fwrite handle->front, goto ERR2);

	ret = fwrite(&handle->end, sizeof(handle->end), 1, fp);
	ERRP(ret != 1, fwrite handle->edn, goto ERR2);

	ret = fwrite(&handle->size, sizeof(handle->size), 1, fp);
	ERRP(ret != 1, fwrite handle->size, goto ERR2);

	ret = fwrite(&handle->max, sizeof(handle->max), 1, fp);
	ERRP(ret != 1, fwrite handle->max, goto ERR2);

	for(i = 0, j = handle->front; i < queue_len(handle); i++, j++)
	{
		ret = fwrite(handle->data + handle->size * j, handle->size, 1, fp);
		ERRP(ret != 1, fwrite handle->data, goto ERR2);

		if(j == handle->max)
		{
			j = 0;
		}
	}

	fclose(fp);

	return ;
ERR2:
	fclose(fp);
ERR1:
	return ;
}

QUEUE *queue_load(char *path)
{
	FILE *fp = NULL;
	QUEUE *handle = NULL;

	int ret;
	int front, end, size, max;
	int i, j;
	int len;
	void *data = NULL;
	fp = fopen(path, "r");
	ERRP(NULL == fp, fopen fp, goto ERR1);

	ret = fread(&front, sizeof(front), 1, fp);
	ERRP(ret != 1, fread front, goto ERR2);

	ret = fread(&end, sizeof(end), 1, fp);
	ERRP(ret != 1, fread ret, goto ERR2);

	ret = fread(&size, sizeof(size), 1, fp);
	ERRP(ret != 1, fread size, goto ERR2);

	ret = fread(&max, sizeof(max), 1, fp);
	ERRP(ret != 1, fread max, goto ERR2);

	handle = queue_create(max, size);
	ERRP(NULL == handle, queue_create handle, goto ERR2);

	if(end > front)
	{
		len = end - front;
	}
	else
	{
		len = max - (front - end);
	}

	handle->front = front;
	handle->end = end;

	for(i = 0, j = front; i <len; i++, j++)
	{
		ret = fread(handle->data + size * j, size, 1, fp);
		ERRP(ret != 1, fread handle->data, goto ERR3);

		if(j == max)
		{
			j = 0;
		}
	}

	fclose(fp);

	return handle;
ERR3:
	free(handle);
ERR2:
	fclose(fp);
ERR1:
	return ;
}

void queue_destory(QUEUE *handle)
{
	free(handle->data);
	free(handle);
}