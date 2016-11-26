#include "queue.h"

QUEUE *queue_create(int size, int max)
{
    QUEUE *handle = NULL; 

    handle = (QUEUE *)malloc(sizeof(QUEUE));
    ERRP(NULL == handle, goto ERR1, 0);

    handle->max = max;

    handle->data = llist_create(size);
    ERRP(NULL == handle->data, goto ERR2, 0);

    handle->save = (void *)malloc(size);
    ERRP(NULL == handle->save, goto ERR3, 0);
    
    return handle;
ERR3:
    llist_destroy(handle->data);
ERR2:
    free(handle);
ERR1:
    return NULL;
}

int queue_isfull(QUEUE *handle)
{
    if (llist_num(handle->data) == handle->max)
        return 1;
    return 0;
}

int queue_isempty(QUEUE *handle)
{
    if (llist_num(handle->data) == 0)
        return 1;
    return 0;
}

int queue_en(void *data, QUEUE *handle)
{
    if (queue_isfull(handle))
        return -1;

    return llist_append(data, handle->data);
}

int queue_num(QUEUE *handle)
{
    return llist_num(handle->data);
}

void *queue_de(QUEUE *handle)
{
    int num = 1;

    if (queue_isempty(handle))
        return NULL;

    memcpy(handle->save, llist_ind(num, handle->data), llist_size(handle->data));

    llist_delete_ind(num, handle->data);

    return handle->save;
}

void queue_travel(queue_op_t *op, QUEUE *handle)
{
    llist_travel((void *)op, handle->data); 
}

void queue_destroy(QUEUE *handle)
{
    llist_destroy(handle->data);
    free(handle->save);
    free(handle);
}
