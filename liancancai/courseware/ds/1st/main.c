#include "darr.h"

#define MAX 10

struct cls_t{
	char name[128];
	int id;
	int age;
	char sex;
	double cn;
	double en;
};

void ls(void *data)
{
	struct cls_t *cls = (struct cls_t *)data;
	printf("name : %6s | id : %d | age : %d | sex : %c | cn : %.2f | en : %.2f\n", cls->name, cls->id, cls->age, cls->sex, cls->cn, cls->en);

}

int cmp_name(void *d1, void *d2)
{
	return strcmp((char *)d1, ((struct cls_t *)d2)->name);
}

int cmp_id(void *d1, void *d2)
{
	return *(int *)d1 - ((struct cls_t *)d2)->id;
}
int sort_id(void *d1, void *d2)
{
	return ((struct cls_t*)d1)->id - ((struct cls_t *)d2)->id;
}
int cmp_age(void *d1, void *d2)
{
	return *(int *)d1 - ((struct cls_t *)d2)->age;
}
int cmp_sex(void *d1, void *d2)
{
	return *(char *)d1 - ((struct cls_t *)d2)->sex;
}
int sort_cn(void *d1, void *d2)
{
	return ((struct cls_t *)d1)->cn - ((struct cls_t *)d2)->cn;
}

void ls_int(void *data)
{
	printf("%d ", *(int *)data);
}

int main(int argc, char **argv)
{
	int i;
	char sex = 'M';
	int num;
	int bit, id, age = 19;
	char name[128];
	struct cls_t cls, stu = {"tom", 10100, 18, 'F', 85.5, 91.6};//临时接受用户输入
	DARR *handle = NULL;
	if (argc >= 2)
	{
		printf("darr_load!\n");
		handle = darr_load("./stu.db");
		printf("len = %d\n", darr_num(handle));
		darr_travel(handle, ls);
	}
	else
	{
		/*printf("a - m = %d\n", 'a' - 'c');// 95 - 97*/

		handle = darr_create(sizeof(struct cls_t));
		ERRP(NULL == handle, darr_create, goto ERR1);

		//表示接受用户数据
		for (i = 0; i < MAX; i++)
		{
			snprintf(cls.name, sizeof(cls.name), "cls_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
			cls.id = rand() % 100 + 10000;
			cls.age = rand() % 3 + 18;
			cls.sex = "MF"[rand() % 2];
			cls.cn = rand() % 20 + 80;
			cls.en = rand() % 30 + 70;

			/*darr_append(&cls, handle);*/
			darr_prevend(&cls, handle);
		}
		darr_travel(handle, ls);
		printf("len = %d\n", darr_num(handle));
		printf("===============\n");
		/*darr_sort(sort_cn, handle);*/
		darr_sort(sort_id, handle, 0);
		printf("sizeof(struct cls_t) = %d\n", sizeof(struct cls_t));
		darr_store("./stu.db", handle);
		
	/*
	 *    printf("please input find age : ");
	 *    scanf("%d", &age);
	 *
	 */
		/*
		 *ls(darr_index_ind(4, handle));
		 *printf("===========\n");
		 */
		
		/*darr_alldel(&age, handle, cmp_age);*/
		/*darr_alldel(&sex, handle, cmp_sex);*/
		/*darr_travel(darr_find(&age, handle, cmp_age), ls);*/
		/*
		 *GETLINES("please input del name : ", name);
		 *printf("name = %s\n", name);
		 *darr_del(name, handle, cmp_name);
		 */
		/*
		 *printf("please input del bit : ");
		 *scanf("%d", &bit);
		 *darr_index_del(bit, handle);
		 */

		/*
		 *printf("please input bit : ");
		 *scanf("%d", &bit);
		 *darr_insert(bit, &stu, handle);
		 */
		//打印
		darr_travel(handle, ls);
		printf("len = %d\n", darr_num(handle));
	}
	//释放
	darr_destroy(handle);

	return 0;
ERR1:
	return -1;
}
