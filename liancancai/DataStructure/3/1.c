#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef void (llist_op_t) (void *);
// typedef void (llist_op_t)(void *);
//获取字符串
#define GETLINES(string, buf) do{							\
						printf(string);						\
						fgets(buf, sizeof(buf), stdin);		\
						if (buf[strlen(buf) - 1] == '\n')	\
							buf[strlen(buf) - 1] = '\0';	\
					}while(0)


//容错宏
#define ERRP(con, func, ret) do{						\
						if (con)						\
						{								\
							printf(#func" failed!\n");	\
							ret;						\
						}								\
					}while(0)

struct node_t{
	void *data;
	struct node_t *next;
	struct node_t *prev;
};

//抽象数据类型
typedef struct llist_t{
	struct node_t head;//数据
	int size;//类型
	int num;//大小
}LLIST;

struct cls_t{
	char name[30];
	int age;
	int id;
	char sex;
};

// LLIST *llist_create(int size)
// {
// 	LLIST *handle = NULL;

// 	handle = (LLIST *)malloc(sizeof(LLIST));
// 	ERRP(NULL == handle, handle malloc, goto ERR1);
	
// 	handle->num = 0;
// 	handle->size = size;
// 	handle->head.data = NULL;
// 	handle->head.next = &handle->head;
// 	handle->head.prev = &handle->head;

// 	return handle;

// ERR1:
// 	return NULL;

// }

LLIST *llist_create(int size)
{
	LLIST *handle = NULL;

	handle = (LLIST *)malloc(sizeof(LLIST));
	ERRP(NULL == handle, malloc handle, goto ERR1);

	handle->head.data = NULL;
	handle->head.next = &handle->head;
	handle->head.prev = &handle->head;//循环双向链表
	handle->size = size;
	handle->num = 0;

	return handle;
ERR1:
	return NULL;
}

// int llist_append(void *data, LLIST *handle)
// {
// 	struct node_t *new = NULL;

// 	new = (struct node_t *)malloc(sizeof(struct node_t ));
// 	ERRP(NULL == new, malloc new, goto ERR1);

// 	new->data = (void *)malloc(handle->size);
// 	ERRP(NULL == new->data, malloc new->data, goto ERR2);

// 	memcpy(new, data, handle->size);

// 	new->next = &handle->head;
// 	new->prev = handle->head.prev;
// 	handle->head.prev->next = new;
// 	handle->head.prev = new;
// 	handle->num ++;

// 	return 1;
// ERR2:
// 	free(new);
// ERR1:
// 	return -1;
// }
  
// int llist_append(void *data, LLIST *handle)
// {
// 	struct node_t *new = NULL;

// 	new = (struct node_t *)malloc(sizeof(struct node_t));
// 	ERRP(NULL == new, malloc new, goto ERR1);

// 	new->data = (void *)malloc(handle->size);
// 	ERRP(new->data == NULL, malloc new->data, goto ERR2);

// 	memcpy(new, data, handle->size);

// 	new->next = &handle->head;
// 	new->prev = handle->head.prev;
// 	handle->head.prev->next = new;
// 	handle->head.prev = new;
// 	handle->num++;

// 	return 0;
// ERR2:
// 	free(new);
// ERR1:
// 	return -1;
// }


//实现后插
int llist_append(void *data, LLIST *handle)
{
	struct node_t *new = NULL;

	new = (struct node_t *)malloc(sizeof(struct node_t));
	ERRP(NULL == new, malloc new, goto ERR1);

	new->data = (void *)malloc(handle->size);
	ERRP(new->data == NULL, malloc new->data, goto ERR2);

	memcpy(new, data, handle->size);

	new->next = &handle->head;
	new->prev = handle->head.prev;
	handle->head.prev->next = new;
	handle->head.prev = new;
	handle->num++;

	return 0;
ERR2:
	free(new);
ERR1:
	return -1;
}

// void llist_travel(LLIST *handle, llist_op_t *op, int flag)
// {
// 	struct node_t *tail = NULL;

// 	if(1 == flag)
// 	{
// 		for(tail = handle->head.next; tail != &handle->head; tail = tail->next)
// 		{
// 			op(tail->data);
// 		}
// 	}
// 	else
// 	{
// 		for(tail = handle->head.prev; tail != &handle->head; tail = tail->prev)
// 		{
// 			op(tail->data);
// 		}
// 	}

// }

void llist_travel(LLIST *handle, llist_op_t *op, int flag)
{
	struct node_t *tail = NULL;

	if (!flag)
	{
		//next
		for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
		{
			op(tail->data);
		}
	}
	else
	{
		for (tail = handle->head.prev; tail != &handle->head; tail = tail->prev)
		{
			op(tail->data);
		}
	}
}

// void ls(void * data)
// {
// 	struct cls_t *stu = (struct cls_t*) data;

// 	printf("%s \n", stu->name);

// }
void ls(void *data)
{
	struct cls_t *stu = (struct cls_t *)data;

	printf("name : %6s | id : %d | age : %d | sex : %c\n",stu->name, stu->id, stu->age, stu->sex);
}

int main(void)
{
	// int i;
	// struct cls_t student_temp;
	// LLIST *handle = NULL;

	// handle = llist_create(sizeof(struct cls_t));//zhe size is use to handle->head's data


	// for(i = 0; i < 10; i++)
	// {
	// 	snprintf(student_temp.name, sizeof(student_temp.name), "stu_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
	// 	student_temp.age = 18 + rand() % 5;
	// 	student_temp.id = 10000 + rand() % 100;
	// 	student_temp.sex = "MG"[rand() % 2]; 
	// 	llist_append(&student_temp, handle);
	// 	// printf("name = %s\n", student_temp.name);
	// 	// printf("age = %d\n", student_temp.age);
	// 	// printf("id = %d\n", student_temp.id);
	// 	// printf("sex = %c\n", student_temp.sex);
	// }

	// llist_travel(handle, ls, 1);	


int i;
	struct cls_t cls;
	LLIST *handle = NULL;

	handle = llist_create(sizeof(struct cls_t));
	ERRP(handle == NULL, llist_create, goto ERR1);

	for (i = 0; i < 10 ; i++) 
	{
		snprintf(cls.name, sizeof(cls.name), "stu_%c%c", rand() % 26 + 'A', rand() % 26 + 'a');
		cls.id = rand() % 100 + 1001000;
		cls.age = rand() % 3 + 19;
		cls.sex = "MF"[rand() % 2];

		llist_append(&cls, handle);
	}

	llist_travel(handle, ls, 0);
	// llist_destroy(handle);

	return 0;
ERR1:
	return -1;
	
}











