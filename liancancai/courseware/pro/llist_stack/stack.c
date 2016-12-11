#include "stack.h"

STACK *stack_create(int size, int max)
{
    STACK *handle = NULL; 

    handle = (STACK *)malloc(sizeof(STACK));
    ERRP(NULL == handle, goto ERR1, 0);

    handle->size = size;
    handle->top = 0;
    handle->max = max;

    handle->head.next = &handle->head;
    handle->head.prev = &handle->head;

    handle->save = (void *)malloc(size);
    ERRP(NULL == handle->save, goto ERR2, 0);
    
    return handle;
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
    struct node_t *new = NULL;

    if (stack_isfull(handle))
        return -1;

    new = (struct node_t *)malloc(sizeof(struct node_t));
    ERRP(NULL == new, goto ERR1, 0);

    new->data = (void *)malloc(handle->size);
    ERRP(NULL == new->data, goto ERR2, 0);

    memcpy(new->data, data, handle->size);

    new->next = &handle->head;
    new->prev = handle->head.prev;
    handle->head.prev->next = new;
    handle->head.prev = new;

    handle->top++;

    return 0;
ERR2:
    free(new);
ERR1:
    return -1;
}

int stack_num(STACK *handle)
{
    return handle->top;
}

void *stack_pop(STACK *handle)
{
    struct node_t *tail = handle->head.prev;

    if (stack_isempty(handle))
        return NULL;

    handle->top--;

    memcpy(handle->save, tail->data, handle->size);

    tail->next->prev = tail->prev;
    tail->prev->next = tail->next;
    free(tail->data);
    free(tail);

    return handle->save;
}

void stack_travel(stack_op_t *op, STACK *handle)
{
    struct node_t *tail = NULL;

    for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
    {
        op(tail->data);
    }
}

void stack_destroy(STACK *handle)
{
    struct node_t *tail = handle->head.next, *save = NULL;

    while (tail != &handle->head)
    {
        save = tail->next; 
        free(tail->data);
        free(tail);
        tail = save;
    }

    free(handle->save);
    free(handle);
}

