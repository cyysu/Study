#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "llist.h"

LLIST *llist_create(int size)
{
    LLIST *handle = NULL;

    handle = (LLIST *)malloc(sizeof(LLIST));
    ERR(NULL == handle, goto ERR1);

    handle->num = 0;
    handle->size = size;
    handle->head.data = NULL;
    handle->head.next = &handle->head;
    handle->head.prev = &handle->head;

    return handle;
ERR1:
    return NULL;
}

void llist_destroy(LLIST *handle, llist_destroy_t *op)
{
    struct node_t *tail = handle->head.next, *save = NULL;

    while (tail != &handle->head)
    {
        save = tail->next; 
        if (op == NULL)
            free(tail->data);
        else
            op(tail->data);
        free(tail);
        tail = save; 
    }
    free(handle);
}

int llist_append(void *data, LLIST *handle)
{
    struct node_t *new = NULL;

    ERR(NULL == data, goto ERR1);
    
    new = (struct node_t *)malloc(sizeof(struct node_t));
    ERR(NULL == new, goto ERR1);
    
    new->data = (void *)malloc(handle->size);
    ERR(NULL == new->data, goto ERR2);

    memcpy(new->data, data, handle->size);

    new->next = &handle->head;
    new->prev = handle->head.prev;
    handle->head.prev->next = new;
    handle->head.prev = new;

    handle->num += 1;

    return 0;
ERR2:
    free(new);
ERR1:
    return -1;
}

int llist_sort_insert(void *data, llist_cmp_t *cmp, LLIST *handle)
{
    struct node_t *new = NULL, *tail = NULL;

    ERR(NULL == data, goto ERR1);
    
    new = (struct node_t *)malloc(sizeof(struct node_t));
    ERR(NULL == new, goto ERR1);
    
    new->data = (void *)malloc(handle->size);
    ERR(NULL == new->data, goto ERR2);

    memcpy(new->data, data, handle->size);

    for (tail = &handle->head; tail->next != &handle->head && cmp(new->data, tail->next->data) > 0; tail = tail->next)
        ;
    
    new->next = tail->next;
    new->prev = tail;
    tail->next->prev = new;
    tail->next = new;

    handle->num += 1;

    return 0;
ERR2:
    free(new);
ERR1:
    return -1;
}

void llist_sort(llist_cmp_t *cmp, LLIST *handle)
{
    struct node_t *v1 = NULL, *v2 = NULL;
    void *val = NULL;

    for (v1 = handle->head.next; v1->next != &handle->head; v1 = v1->next)
    {
        for (v2 = v1->next; v2 != &handle->head; v2 = v2->next)
        {
            if (cmp(v1->data, v2->data) > 0)
            {
                val = v1->data;
                v1->data = v2->data;
                v2->data = val;
            }
        }
    }
}

int llist_delete(void *key, llist_cmp_t *cmp, llist_destroy_t *op, LLIST *handle)
{
    struct node_t *tail = NULL;

    for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
    {
        if (cmp(key, tail->data) == 0) 
        {
            tail->next->prev = tail->prev;
            tail->prev->next = tail->next;
            if (op == NULL)
                free(tail->data); 
            else
                op(tail->data);
            free(tail);
            handle->num -= 1;
            return 0;
        }
    }

    return -1;
}

int llist_deleteall(void *key, llist_cmp_t *cmp, llist_destroy_t *op, LLIST *handle)
{
    struct node_t *tail = handle->head.next, *save = NULL;
    int count = 0;

    while (tail != &handle->head)
    {
        save = tail->next;
        if (cmp(key, tail->data) == 0) 
        {
            tail->next->prev = tail->prev;
            tail->prev->next = tail->next;
            if (op == NULL)
                free(tail->data); 
            else
                op(tail->data);
            free(tail);
            count++;
            handle->num -= 1;
        }
        tail = save;
    }

    return count;
}

void *llist_find(void *key, llist_cmp_t *cmp, LLIST *handle)
{
    struct node_t *tail = NULL;

    for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
    {
        if (cmp(key, tail->data) == 0) 
            return tail->data;
    }
    return NULL;
}

LLIST *llist_findall(void *key, llist_cmp_t *cmp, LLIST *handle)
{
    struct node_t *tail = NULL; 
    LLIST *find = NULL;

    find = llist_create(sizeof(void *));
    ERR(NULL == find, goto ERR1);

    for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
    {
        if (cmp(key, tail->data) == 0) 
            llist_append(&tail->data, find);
    }
    return find;
ERR1:
    return NULL;
}

void llist_travel(llist_op_t *op, void *args, LLIST *handle)
{
    struct node_t *tail = NULL;

    for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
    {
        op(tail->data, args);
    }
}

int llist_store(const char *path, llist_file_t *op, LLIST *handle)
{
    FILE *fp = NULL;
    struct node_t *tail = NULL;

    fp = fopen(path, "w");
    ERR(NULL == fp, goto ERR1);

    fwrite(MAGIC, sizeof(char), strlen(MAGIC), fp);

    fwrite(&handle->num, sizeof(handle->num), 1, fp);
    fwrite(&handle->size, sizeof(handle->size), 1, fp);

    for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
    {
        if (op == NULL)
            fwrite(tail->data, handle->size, 1, fp); 
        else
            op(tail->data, fp);
    }

    fclose(fp);

    return 0;
ERR1:
    return -1;
}

LLIST *llist_load(const char *path, llist_file_t *op)
{
    FILE *fp = NULL;
    char buf[128];
    int ret, num ,size, i;
    LLIST *handle = NULL;
    void *new = NULL;

    fp = fopen(path, "r");
    ERR(NULL == fp, goto ERR1);

    ret = fread(buf, sizeof(char), strlen(MAGIC), fp);
    ERR(ret != strlen(MAGIC) ||
        strncmp(buf, MAGIC, strlen(MAGIC)), goto ERR2);

    ret = fread(&num, sizeof(num), 1, fp);
    ERR(ret != 1, goto ERR2);
    ret = fread(&size, sizeof(size), 1, fp);
    ERR(ret != 1, goto ERR2);

    handle = llist_create(size);
    ERR(NULL == handle, goto ERR2);

    new = (void *)malloc(size);
    ERR(NULL == new, goto ERR3);

    for (i = 0; i < num; i++)
    {
        if (op == NULL)
        {
            ret = fread(new, size, 1, fp); 
            ERR(ret != 1, goto ERR4);
        }
        else
            ERR(op(new, fp), goto ERR4);
        ERR(llist_append(new, handle), goto ERR4);
    }

    free(new);

    fclose(fp);

    return handle;

ERR4:
    free(new);
    llist_destroy(handle, NULL);
    goto ERR2;
ERR3:
    free(handle);
ERR2:
    fclose(fp);
ERR1:
    return NULL;
}
