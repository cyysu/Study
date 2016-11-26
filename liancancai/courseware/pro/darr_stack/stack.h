#ifndef __KEN_STACK_H__
#define __KEN_STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct stack_t {
    int size;
    int top;
    int max;
    void *data;
    void *save;
}STACK;

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

typedef void (stack_op_t)(const void *);

STACK *stack_create(int size, int max);
int stack_isfull(STACK *handle);
int stack_isempty(STACK *handle);
int stack_push(void *data, STACK *handle);
int stack_num(STACK *handle);
void *stack_pop(STACK *handle);
void stack_travel(stack_op_t *op, STACK *handle);
void stack_destroy(STACK *handle);

#endif /* __STACK_H__ */
