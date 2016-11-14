#include "queue_llist.h"

void ls_int(void *data)
{
	printf("%d ", *(int *)data);
}

struct cls_t {
	char name[20];
	int age;
	int id;
	char sex;
};


void ls(void *data)
{
	struct cls_t *stu = (struct cls_t *)data;
	printf("name = %s, age = %d, id = %d, sex = %c\n", stu->name, stu->age, stu->id, stu->sex);
}
int main(int argc, char *argv[])
{
	int i;
	QUEUE_LLIST *queue = NULL;
	struct cls_t cls ;

	queue = queue_llist_create(sizeof(struct cls_t), QUEUE_LLIST_MAX);

	if(strcmp(argv[1], "write") == 0)
	{
		for(i = 0; i < 5; i++)
		{
			snprintf(cls.name, sizeof(cls.name), "stu_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
			printf("cls.name = %s\n", cls.name);
			cls.age = i + 1;
			cls.id = 10000 + rand() % 20;
			cls.sex = "MG"[rand() % 2];

			queue_llist_in(&cls, queue);
		}
		// ls_int(queue_llist_out(queue));
		// ls_int(queue_llist_out(queue));

		queue_llist_store("./queue_llist.db", queue);
		printf("write dont \n");
	}

	if(strcmp(argv[1], "read") == 0)
	{
		 queue = queue_llist_load("./queue_llist.db");
	}

	queue_llist_travel(queue, ls);
	putchar(10);


	queue_llist_destory(queue);
	return 0;
}