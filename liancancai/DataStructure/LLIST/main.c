#include "llist.h"

#define MAX 10

struct cls_t{
	char name[30];
	int age;
	int id;
	char sex;
};

void ls(void *data)
{
	struct cls_t *stu = (struct cls_t *)data;
	printf("%s %2d %2d %c\n", stu->name, stu->age, stu->id, stu->sex);
}

int main(void)
{

	struct cls_t cls;
	LLIST *handle;
	int i;

	handle = llist_create(sizeof(struct cls_t));

	handle = llist_read("./test_");
	llist_travel(handle, ls, 1);
	for(i = 0; i < MAX; i ++)
	{
		snprintf(cls.name,sizeof(cls.name), "stu_%c%c", rand() % 26 + 'a', rand() % 26 + 'A');
		cls.age = 18 + rand() % 5;
		cls.id = i + 1;
		cls.sex = "MG"[rand() % 2];
		llist_append(&cls, handle);
	}

	// printf("sizeof(struct cls_t) = %ld\n", sizeof(struct cls_t));
	// llist_travel(handle, ls, 1);
	// printf("======================\n");
	// llist_travel(handle, ls, 2);
	llist_write("./test_", handle);


	return 0;
}