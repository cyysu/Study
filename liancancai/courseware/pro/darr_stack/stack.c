#include "stack.h"

STACK *stack_create(int size, int max)
{
    STACK *handle = NULL; 

    handle = (STACK *)malloc(sizeof(STACK));
    ERRP(NULL == handle, goto ERR1, 0);

    handle->size = size;
    handle->top = 0;
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

int stack_isfull(STACK *handle)
{
    if (handle->top == handle->max)
        return 1;
    return 0;
}

int stack_isempty(STACK *handle)
{
    if (handle->top == 0)
        return 1;
    return 0;
}

int stack_push(void *data, STACK *handle)
{
    if (stack_isfull(handle))
        return -1;
    memcpy(handle->data + handle->top * handle->size, 
                data, handle->size);
    handle->top++;

    return 0;
}

int stack_num(STACK *handle)
{
    return handle->top;
}

void *stack_pop(STACK *handle)
{
    if (stack_isempty(handle))
        return NULL;

    handle->top--;

    memcpy(handle->save, handle->data + handle->top * handle->size, handle->size);

    return handle->save;
}

void stack_travel(stack_op_t *op, STACK *handle)
{
    int i;

    for (i = 0; i < handle->top; i++)
    {
        op(handle->data + i * handle->size); 
    }
}

void stack_destroy(STACK *handle)
{
    free(handle->save);
    free(handle->data);
    free(handle);
}

