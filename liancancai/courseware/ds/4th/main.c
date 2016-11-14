#include "stack.h"

#define MAX 10

void ls(void *data)
{
	printf("%d ", *(int *)data);
}
void ls_char(void *data)
{
	printf("%c ", *(char *)data);
}
void ls_str(void *data)
{
	printf("%s\n", ((struct str_t *)data)->buf);
}
void ls_buf(void *data)
{
	printf("%s\n", (char *)data);
}

int main(void)
{
	int num;
	char ch;
	int i;
	char buf[128];
	STACK *handle = NULL;

	/*handle = stack_create(MAX, sizeof(int));*/
	handle = stack_create(128, sizeof(buf));
	ERRP(handle == NULL, srack_create, goto ERR1);


	for (i = 0; i < MAX; i++)
	{
		/*num = rand() % 100;*/
		/*ch = rand() % 26 + 'A';*/
		snprintf(buf, sizeof(buf), "name_%d", i + 1);
		stack_push(buf, handle);
	}

	stack_travel(handle, ls_buf);
	printf("\n");
	stack_destroy(handle);

	return 0;
ERR1:
	return -1;
}
