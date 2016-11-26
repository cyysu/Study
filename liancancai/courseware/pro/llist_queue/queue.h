#ifndef __KEN_QUEUE_H__
#define __KEN_QUEUE_H__

#include "llist.h"

typedef struct queue_t {
    int max;
    LLIST *data;
    void *save;
}QUEUE;

typedef void (queue_op_t)(const void *);

QUEUE *queue_create(int size, int max);
int queue_isfull(QUEUE *handle);
int queue_isempty(QUEUE *handle);
int queue_en(void *data, QUEUE *handle);
int queue_num(QUEUE *handle);
void *queue_de(QUEUE *handle);
void queue_travel(queue_op_t *op, QUEUE *handle);
void queue_destroy(QUEUE *handle);

#endif /* __KEN_QUEUE_H__ */
