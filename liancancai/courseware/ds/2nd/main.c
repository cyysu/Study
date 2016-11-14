#include "llist.h"

#define MAX 10

struct cls_t{
	char name[128];
	int id;
	int age;
	char sex;
};
int sort_id(void *d1, void *d2)
{
	return ((struct cls_t *)d1)->id - ((struct cls_t *)d2)->id;
}
int sort_age(void *d1, void *d2)
{
	return ((struct cls_t *)d1)->age - ((struct cls_t *)d2)->age;
}
int cmp_name(void *d1, void *d2)
{
	return strcmp((char *)d1, ((struct cls_t *)d2)->name);
}
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
int main(int argc, char **argv)
{
	int i;
	struct cls_t cls, stu = {"tom", 1001111, 20, 'M'};
	int age = 21, index, bit;
	char sex = 'M';
	char name[128];
	LLIST *handle = NULL;
	struct cls_t *p = NULL;

	if (argc >= 2)
	{
		printf("llist_load!\n");
		handle = llist_load("./stu.db");
		llist_travel(handle, ls, 0);
	}
	else
	{
		handle = llist_create(sizeof(struct cls_t));
		ERRP(handle == NULL, llist_create, goto ERR1);

		for (i = 0; i < MAX; i++)
		{
			snprintf(cls.name, sizeof(cls.name), "stu_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
			cls.id = rand() % 100 + 1001000;
			cls.age = rand() % 3 + 19;
			cls.sex = "MF"[rand() % 2];

			/*llist_append(&cls, handle);*/
			llist_prevend(&cls, handle);
		}

		llist_travel(handle, ls, 0);
		printf("===============\n");
		llist_sort(sort_age, handle);
		printf("sizeof(struct cls_t) = %d\n", sizeof(struct cls_t));
		llist_store("./stu.db", handle);
		/*
		 *printf("please input bit : ");
		 *scanf("%d", &bit);
		 *p = llist_index_ind(bit, handle);
		 *[>GETLINES("please input ind name : ", name);<]
		 *[>llist_del(name, cmp_name, handle);<]
		 *[>p = llist_ind(name, cmp_name, handle);<]
		 *if (p == NULL)
		 *{
		 *    printf("no find!\n");
		 *}
		 *else
		 *{
		 *    ls(p);
		 *}
		 */
		printf("===============\n");
		/*llist_index_insert(10, &stu, handle);*/

		llist_travel(handle, ls, 0);
		/*
		 *printf("please input del age : ");
		 *scanf("%d", &age);
		 */
		/*llist_all_del(&sex, cmp_sex,  handle);*/
		/*llist_travel(llist_find(&sex, cmp_sex, handle), ls, 0);*/
		/*llist_travel(llist_find(&age, cmp_age, handle), ls, 0);*/

		/*
		 *printf("============\n");
		 *llist_travel(handle, ls, 1);
		 */
	}
	llist_destroy(handle);

	return 0;
ERR1:
	return -1;
}
