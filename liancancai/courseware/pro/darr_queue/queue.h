#ifndef __KEN_QUEUE_H__
#define __KEN_QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct queue_t {
    int size;
    int front;
    int end;
    int max;
    void *data;
    void *save;
}QUEUE;

#define DEBUG0(...)     
#define DEBUG1(...)     fprintf(stderr, __VA_ARGS__);

#define ERRP(con, ret, flag, ...)       do          \
            {                                       \
                if (con)                            \
                {                                   \
                    DEBUG##flag(__VA_ARGS__)        \
                    ret;                            \
                }                                   \
            } while (0)

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
