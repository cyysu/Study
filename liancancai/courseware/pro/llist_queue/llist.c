#include "llist.h"

LLIST *llist_create(int size)
{
    LLIST *handle = NULL;

    handle = (LLIST *)malloc(sizeof(LLIST));
    ERRP(NULL == handle, return NULL, 0);

    handle->size = size;
    handle->num = 0;
    handle->head.next = &handle->head;
    handle->head.prev = &handle->head;

    return handle;
}

int insert(void *data, int index, llist_cmp_t *cmp, LLIST *handle)
{
    struct node_t *new = NULL, *tail = NULL;

    new = (struct node_t *)malloc(sizeof(struct node_t));
    ERRP(NULL == new, goto ERR1, 0);

    new->data = (void *)malloc(handle->size);
    ERRP(NULL == new->data, goto ERR2, 0);

    memcpy(new->data, data, handle->size);

    if (index == PREPEND || index < SORT)
        tail = &handle->head;
    else if (index == APPEND || index > handle->num)
        tail = handle->head.prev;
    else if (index == SORT)
    {
        for (tail = &handle->head; 
                tail->next != &handle->head && 
                cmp(tail->next->data, new->data) < 0; 
                tail = tail->next)
            ;
    }
    else
    {
        for (tail = &handle->head; 
                --index && tail->next != &handle->head;
                tail = tail->next)
            ;
    }

    new->next = tail->next;
    new->prev = tail;
    tail->next->prev = new;
    tail->next = new;

    handle->num++;

    return 0;
ERR2:
    free(new);
ERR1:
    return -1;
}

int llist_append(void *data, LLIST *handle)
{
    return insert(data, APPEND, NULL, handle);
}

int llist_prepend(void *data, LLIST *handle)
{
    return insert(data, PREPEND, NULL, handle);
}

int llist_insert_sort(void *data, llist_cmp_t *cmp, LLIST *handle)
{
    return insert(data, SORT, cmp, handle);
}

int llist_insert(void *data, int index, LLIST *handle)
{
    if (index == SORT)
        return -1;
    return insert(data, index, NULL, handle);
}

int llist_num(LLIST *handle)
{
    return handle->num;
}

int llist_size(LLIST *handle)
{
    return handle->size;
}

void *llist_ind(int index, LLIST *handle)
{
    int i;
    struct node_t *tail = NULL;

    ERRP(index < 1 || index > handle->num, return NULL, 0);

    for (tail = handle->head.next, i = 1;
            tail != &handle->head && i != index;
            tail = tail->next, i++)
        ;
    return tail->data;
}

int llist_delete_ind(int index, LLIST *handle)
{
    int i;
    struct node_t *tail = NULL;

    ERRP(index < 1 || index > handle->num, return -1, 0);

    for (tail = handle->head.next, i = 1;
            tail != &handle->head && i != index;
            tail = tail->next, i++)
        ;
    tail->next->prev = tail->prev;
    tail->prev->next = tail->next;

    free(tail->data);
    free(tail);

    handle->num--;

    return 0;
}

void *llist_find(void *key, llist_cmp_t *cmp, LLIST *handle)
{
    struct node_t *tail = NULL;

    for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
    {
        if (!cmp(key, tail->data))  
            return tail->data;
    }

    return NULL;
}

int llist_delete(void *key, llist_cmp_t *cmp, LLIST *handle)
{
    struct node_t *tail = NULL, *save = NULL;

    for (tail = handle->head.next; tail != &handle->head; tail = save)
    {
        save = tail->next;
        if (!cmp(key, tail->data))  
        {
            tail->next->prev = tail->prev; 
            tail->prev->next = tail->next;
            free(tail->data);
            free(tail);
            return 0;
        }
    }

    return -1;

}

void llist_sort(llist_cmp_t *cmp, LLIST *handle)
{
    struct node_t *tail = NULL, *val = NULL;
    void *t = NULL;

    for (tail = handle->head.next; tail->next != &handle->head; tail = tail->next)
    {
        for (val = tail->next; val != &handle->head; val = val->next) 
        {
            if (cmp(tail->data, val->data) > 0)
            {
                t = tail->data;
                tail->data = val->data;
                val->data = t;
            }
        }
    }
}

int llist_store(const char *path, LLIST *handle)
{
    FILE *fp = NULL;
    struct node_t *tail = NULL;

    fp = fopen(path, "w");
    ERRP(NULL == fp, return -1, 0);

    fwrite(&handle->size, sizeof(handle->size), 1, fp);
    fwrite(&handle->num, sizeof(handle->num), 1, fp);

    for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
    {
        fwrite(tail->data, handle->size, 1, fp); 
    }

    fclose(fp);

    return 0;
}

LLIST *llist_load(const char *path)
{
    FILE *fp = NULL;
    struct node_t *tail = NULL;
    int size, num, ret, i;
    LLIST *handle = NULL;
    void *t = NULL;

    fp = fopen(path, "r");
    ERRP(NULL == fp, goto ERR1, 0);

    ret = fread(&size, sizeof(size), 1, fp);
    ERRP(ret != 1, goto ERR2, 0);
    ret = fread(&num, sizeof(num), 1, fp);
    ERRP(ret != 1, goto ERR2, 0);

    handle = llist_create(size);
    ERRP(NULL == handle, goto ERR2, 0);

    t = (void *)malloc(size);
    ERRP(NULL == t, goto ERR3, 0);

    for (i = 0; i < num; i++)
    {
        ret = fread(t, size, 1, fp); 
        ERRP(ret != 1, goto ERR4, 0);

        ret = llist_append(t, handle);
        ERRP(ret == -1, goto ERR4, 0);
    }

    free(t);
    fclose(fp);

    return handle;
ERR4:
    free(t);
    llist_destroy(handle);
ERR3:
    free(handle);
ERR2:
    fclose(fp);
ERR1:
    return NULL;
}

void llist_travel(llist_op_t *op, LLIST *handle)
{
    struct node_t *tail = NULL;

    for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
    {
        op(tail->data);
    }
}

void llist_destroy(LLIST *handle)
{
    struct node_t *tail = handle->head.next, *save = NULL;

    while (tail != &handle->head)
    {
        save = tail->next; 
        free(tail->data);
        free(tail);
        tail = save;
    }

    free(handle);
}

