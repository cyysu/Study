#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX 10

typedef void (darr_op_t)(void *);


//抽象数据类型
typedef struct darr_t{
	void *data;//表示所有的数据
	int size;//表示类型
	int num;//表示空间大小
}DARR;

struct cls_t{
	char name[128];
	int id;
	int age;
	char sex;
	double cn;
	double en;
};

DARR *darr_create(int size)
{
	DARR *handle = NULL;

	handle = (DARR *)malloc(sizeof(DARR));
	if (handle == NULL)
	{
		printf("malloc handle failed!\n");
		return NULL;
	}
	handle->data = NULL;
	handle->size = size;
	handle->num = 0;

	return handle;
}
//int -> user -> save -> malloc count -> printf -> free

//data : 表示用户输入数据
//prev : 表示原来数据
//count : 表示数据长度
//size : 表示数据类型
//ret : 表示所有数据
/*void insert(void *data, void *prev, int *count, int size)*/
void insert(void *data, DARR *handle)
/*struct cls_t *insert(struct cls_t cls, struct cls_t *prev, int *count)*/
{
	//申请数据空间
	void*new = NULL;

	new = (void *)malloc(handle->size * (handle->num + 1));
	if (NULL == new)
	{
		printf("malloc failed!\n");
		return ;
	}

	//添加数据到空间地址中
	memcpy(new, handle->data, handle->size * handle->num);
	free(handle->data);
	/*new[*count] = cls;*/
	memcpy(new + handle->num * handle->size, data, handle->size);
	handle->data = new;
	handle->num++;
	/*prev = new;*/

}

//遍历函数
void darr_travel(DARR *handle, darr_op_t *op)
{
	int i;
	for (i = 0; i < handle->num; i++)
	{
		op(handle->data + i * handle->size);
	}
}

void ls(void *data)
{
	struct cls_t *cls = (struct cls_t *)data;
	printf("name : %s | id : %d | age : %d | sex : %c | cn : %.2f | en : %.2f\n", cls->name, cls->id, cls->age, cls->sex, cls->cn, cls->en);

}
int main(void)
{
	int i;
	int count = 0;
	struct cls_t cls;//临时接受用户输入
	struct cls_t *new = NULL;//用来存储用户数据所有数据
	struct cls_t *prev = NULL;//用来保存原来数据
	DARR *handle = NULL;

	handle = darr_create(sizeof(struct cls_t));
	if (handle == NULL)
	{
		printf("darr_create failed!\n");
		return -1;
	}
	//表示接受用户数据
	for (i = 0; i < MAX; i++)
	{
		/*num = rand() % 100;*/
		snprintf(cls.name, sizeof(cls.name), "cls_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
		cls.id = rand() % 100 + 10000;
		cls.age = rand() % 3 + 18;
		cls.sex = "MF"[rand() % 2];
		cls.cn = rand() % 20 + 80;
		cls.en = rand() % 30 + 70;

		/*new = insert(&cls, new, &count, sizeof(struct cls_t));*/
		insert(&cls, handle);
	}

	//打印
	darr_travel(handle, ls);
	//释放

	return 0;
}
