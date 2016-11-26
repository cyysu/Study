#include "queue.h"

#define MAX     10

void ls(const void *data)
{
    printf("%d ", *(int *)data);
}

int main(void)
{
    QUEUE *handle = NULL;
    int n, i;
    int *p = NULL;

    handle = queue_create(sizeof(int), MAX);

    for (i = 0; i < MAX * 2; i++)
    {
        n = rand() % 100;
        printf("%d ", n);
        queue_en(&n, handle);
    }
    printf("\n");

    queue_travel(ls, handle);
    printf("\n");

    printf("1 = %d\n", *(int *)queue_de(handle));

    for (i = 0; i < MAX + 2; i++)
    { 
        p = queue_de(handle);
        if (p == NULL)
            printf("空 ");
        else
            printf("%d ",  *p);
    }
    printf("\n");

    queue_destroy(handle);

    return 0;
}
