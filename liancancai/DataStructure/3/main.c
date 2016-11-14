#include "llist.h"

#define MAX 10

struct cls_t{
	char name[128];
	int id;
	int age;
	char sex;
};

// int cmp_age(void *d1, void *d2)
// {
// 	return *(int *)d1 - ((struct cls_t *)d2)->age;
// }

int cmp_age(void *d1, void *d2)
{
	return *(int *)d1 - ((struct cls_t *)d2)->age;
}
int cmp_sex(void *d1, void *d2)
{
	return *(char *)d1 - ((struct cls_t *)d2)->sex;
}
void ls(void *data)
{
	struct cls_t *stu = (struct cls_t *)data;

	printf("name : %6s | id : %d | age : %d | sex : %c\n",stu->name, stu->id, stu->age, stu->sex);
}
int main(void)
{
	int i;
	struct cls_t cls;
	int age = 21;
	char sex = 'M';
	LLIST *handle = NULL;

	handle = llist_create(sizeof(struct cls_t));
	ERRP(handle == NULL, llist_create, goto ERR1);

	for (i = 0; i < MAX; i++)
	{
		snprintf(cls.name, sizeof(cls.name), "stu_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
		// cls.id = rand() % 100 + 1001000;
		cls.id = i;
		cls.age = rand() % 3 + 19;
		cls.sex = "MF"[rand() % 2];

		// llist_append(&cls, handle);
		llist_prevend(&cls, handle);
	}

	llist_travel(handle, ls, 0);
	cls.id = 333;
	printf("please input del age : ");
	scanf("%d", &age);
     
	// llist_all_del(&sex, cmp_sex,  handle);

	printf("===============\n");

	llist_index_insert(age, &cls, handle);
    llist_travel(handle, ls, 0);
	
	// llist_travel(llist_find(&sex, cmp_sex, handle), ls, 0);
	// llist_travel(llist_find(&age, cmp_age, handle), ls, 0);

    /*
	 *printf("============\n");
	 *llist_travel(handle, ls, 1);
     */
	// llist_destroy(handle);

	return 0;
ERR1:
	return -1;
}
