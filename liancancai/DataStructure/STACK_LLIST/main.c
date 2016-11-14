#include "stack_llist.h"

// STACK *stack_llist_create(int size, int num, int max);
// void stack_llist_push(void *data, STACK * handle);
// void stack_llist_pop(STACK *handle);

// int stack_llist_is_full(STACK *handle);
// int stack_llist_is_empty(STACK *handle);

// void stack_llist_destroy(STACK *handle);
// void stack_llist_store(char *path, STACK *handle);
// void stack_llist_load(char *path);
// void stack_llist_travel(STACK *handle, stack_llist_op_t *op);
#define MAX 20

struct cls_t {
	char name[20];
	int age;
	int id;
	char sex;
};

void ls_int(void *data)
{
	printf("%d\n", *(int *)data);
}

void ls(void *data)
{
	struct cls_t *stu = (struct cls_t *)data;
	printf("name: %s, age: %d, id: %d, sex: %c\n", stu->name, stu->age, stu->id, stu->sex);
}



int main(int argc, char *argv[])
{
	int num;
	int i;
	STACK *handle = NULL;
	struct cls_t cls;

	// handle = stack_llist_create(sizeof(int), MAX);
	handle = stack_llist_create(sizeof(struct cls_t), MAX);

	for(i = 0; i < 10 ; i++)
	{
		snprintf(cls.name, sizeof(cls.name), "stu_%c%c", rand() % 26 +'A', rand() % 26 + 'a');
		cls.age = 18 + rand() %5;
		cls.id = i + 1;
		cls.sex = "MG"[rand() % 2];
		// stack_llist_push(&i, handle);
		stack_llist_push(&cls, handle);
	}
	stack_llist_travel(handle, ls);

	printf("=============\n");
	stack_llist_pop(handle);
	stack_llist_travel(handle, ls);

	printf("==============\n");
	stack_llist_push(&cls, handle);
	stack_llist_push(&cls, handle);
	stack_llist_travel(handle, ls);
	// if(strcmp(argv[1], "write") == 0)
	// {
	// 	stack_llist_store("./stack_llist.db", handle);
	// }

	// if(strcmp(argv[1], "read") == 0)
	// {
	// 	handle = stack_llist_load("./stack_llist.db");
	// }
	// stack_llist_store("./stack_llist.db", handle);
	// handle = stack_llist_load("./stack_llist.db");
	// stack_llist_travel(handle, ls);
	// putchar(10);
	// stack_llist_pop(handle);
	// stack_llist_travel(handle, ls_int);
	// putchar(10);



	stack_llist_destroy(handle);
	return 0;
}