#include "stack.h"


struct cls_t{
	char name[128];
	int id;
	int age;
	char sex;
};


void stack_ls(void *data)
{
	struct cls_t *cls = (struct cls_t *)data;
	printf("name = %s, id = %d, age = %d, sex = %c\n", cls->name, cls->age, cls->id, cls->sex);

}

void stack_ls_int(void *data)
{
	int *i = (int *)data;
	printf("%d\n", *i);
}
// STACK *stack_create(int max, int size);
// int stack_isfull(STACK *handle);
// int stack_isempty(STACK *handle);

// void stack_push(void *data, STACK *handle);
// void stack_pop(STACK *handle);
// void stack_travel(STACK *handle, stack_op_t *op);
// void stack_destroy(STACK *handle);

// void stack_store(char *path, STACK *handle);
// STACK *stack_load(char *path);


int main(void)
{
	int i;

	STACK *stack = NULL;

	stack = stack_create(MAX, sizeof(int));

	// for( i = 0; i < 10; i++)
	// {
	// 	stack_push(&i, stack);
	// }

	// stack_store("./stack.db", stack);
	// printf("stack_store done!\n");
	
	stack = stack_load("./stack.db");

	stack_travel(stack, stack_ls_int);


	return 0;
}