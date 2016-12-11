#include "stack.h"

#define MAX     10

void ls(const void *data)
{
    printf("%d ", *(int *)data);
}


int main(void)
{
    STACK *handle = NULL;
    int n, i;
    int *p = NULL;

    handle = stack_create(sizeof(int), MAX);

    for (i = 0; i < MAX * 2; i++)
    {
        n = rand() % 100;
        printf("%d ", n);
        stack_push(&n, handle);
    }
    printf("\n");

    stack_travel(ls, handle);
    printf("\n");

    printf("1 = %d\n", *(int *)stack_pop(handle));

    for (i = 0; i < MAX + 2; i++)
    { 
        p = stack_pop(handle);
        if (p == NULL)
            printf("空 ");
        else
            printf("%d ",  *p);
    }
    printf("\n");

    stack_destroy(handle);

    return 0;
}
