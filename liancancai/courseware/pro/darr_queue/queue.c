#include "queue.h"

QUEUE *queue_create(int size, int max)
{
    QUEUE *handle = NULL; 

    handle = (QUEUE *)malloc(sizeof(QUEUE));
    ERRP(NULL == handle, goto ERR1, 0);

    handle->size = size;
    handle->front = 0;
    handle->end = 0;
    handle->max = max;
    handle->data = (void *)malloc(max * size);
    ERRP(NULL == handle->data, goto ERR2, 0);

    handle->save = (void *)malloc(size);
    ERRP(NULL == handle->save, goto ERR3, 0);
    
    return handle;
ERR3:
    free(handle->data);
ERR2:
    free(handle);
ERR1:
    return NULL;
}

int queue_isfull(QUEUE *handle)
{
    if ((handle->end + 1) % handle->max == handle->front)
        return 1;
    return 0;
}

int queue_isempty(QUEUE *handle)
{
    if (handle->end == handle->front)
        return 1;
    return 0;
}

int queue_en(void *data, QUEUE *handle)
{
    if (queue_isfull(handle))
        return -1;

    memcpy(handle->data + handle->end * handle->size, 
                data, handle->size);
    handle->end++;

    if (handle->end == handle->max)
        handle->end = 0;

    return 0;
}

int queue_num(QUEUE *handle)
{
    if (handle->front < handle->end)
        return handle->end - handle->front;
    return handle->max - (handle->front - handle->end);
}

void *queue_de(QUEUE *handle)
{
    if (queue_isempty(handle))
        return NULL;

    memcpy(handle->save, handle->data + handle->front * handle->size, handle->size);
    handle->front++;
    /*handle->front %= handle->max;*/
    if (handle->front == handle->max)
        handle->front = 0;

    return handle->save;
}

void queue_travel(queue_op_t *op, QUEUE *handle)
{
    int i, j;
    int len = queue_num(handle);

    for (i = 0, j = handle->front; i < len; i++, j++)
    {
        if (j == handle->max)
            j = 0;
        op(handle->data + j * handle->size); 
    }
}

void queue_destroy(QUEUE *handle)
{
    free(handle->save);
    free(handle->data);
    free(handle);
}

