#include "queue.h"

void ls_int(void *data)
{
	printf("%d ", *(int *)data);
}

int main(int argc, char *argv[])
{
	QUEUE *queue = NULL;
	int i;
	queue = queue_create(QUEUE_MAX, sizeof(int));

	if(strcmp(argv[1], "write") == 0)
	{
		for(i = 0; i < 10; i++)
		{
			queue_in(&i, queue);
		}
		queue_out(queue);
		queue_out(queue);
		
		queue_store("./queue.db", queue);
		printf("write done\n");
	}

	if(strcmp(argv[1], "read") == 0)
	{
		queue = queue_load("./queue.db");
		printf("read done\n");
	}
	queue_travel(queue, ls_int);

	putchar(10);

	queue_destory(queue);
	
	return 0;
}