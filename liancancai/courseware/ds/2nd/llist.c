#include "llist.h"

LLIST *llist_create(int size)
{
	LLIST *handle = NULL;

	handle = (LLIST *)malloc(sizeof(LLIST));
	ERRP(NULL == handle, malloc handle, goto ERR1);

	handle->head.data = NULL;
	handle->head.next = &handle->head;
	handle->head.prev = &handle->head;//循环双向链表
	handle->size = size;//struct cls_t new->data
	handle->num = 0;

	return handle;
ERR1:
	return NULL;
}
//实现后插
int llist_append(void *data, LLIST *handle)
{
	struct node_t *new = NULL;

	new = (struct node_t *)malloc(sizeof(struct node_t));
	ERRP(NULL == new, malloc new, goto ERR1);

	new->data = (void *)malloc(handle->size);
	ERRP(new->data == NULL, malloc new->data, goto ERR2);

	memcpy(new->data, data, handle->size);
	//用户传递数据保存到节点信息中
	//====================
	//把new节点信息插入到链表handle->head中

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

//头插
int llist_prevend(void *data, LLIST *handle)
{
	//1 接受用户数据data -> int char struct => data 要保存到链表节点信息中。
	//2 定义一个链表节点，用来保存数据 new
	//3 申请空间 new
	//4 new->data 
	//5 数据保存到new->data
	//6 新的节点连接到head(handle)

	struct node_t *new = NULL;

	ERRP(data == NULL, llist_prevend option, goto ERR1);

	new = (struct node_t *)malloc(sizeof(struct node_t));
	ERRP(NULL == new, malloc new, goto ERR1);

	new->data = (void *)malloc(handle->size);
	ERRP(new->data == NULL, malloc new->data, goto ERR2);

	memcpy(new->data, data, handle->size);
	
	new->next = handle->head.next;
	new->prev = &handle->head;
	handle->head.next->prev = new;
	handle->head.next = new;
	handle->num++;

	return 0;
ERR2:
	free(new);
ERR1:
	return -1;
}

//指定位置插入
int llist_index_insert(int index, void *data, LLIST *handle)
{
	struct node_t *tail = NULL;

	ERRP(index < 0 || index > handle->num, llist_index_insert option_1, goto ERR1);

	ERRP(data == NULL, llist_index_insert option_2, goto ERR1);

	struct node_t *new = NULL;

	new = (struct node_t *)malloc(sizeof(struct node_t));
	ERRP(NULL == new, malloc new, goto ERR1);

	new->data = (void *)malloc(handle->size);
	ERRP(new->data == NULL, malloc new->data, goto ERR2);

	memcpy(new->data, data, handle->size);
	
	for (tail = &handle->head; tail->next != &handle->head && index--; tail = tail->next)
		;	
	
	//新的节点添加到tail后面
	new->next = tail->next;
	new->prev = tail;
	tail->next->prev = new;
	tail->next = new;
	handle->num++;
	
	return 0;
ERR2:
	free(new);
ERR1:
	return -1;
}

//删除第一个满足条件
int llist_del(void *key, llist_cmp_t *cmp, LLIST *handle)
{
	struct node_t *tail = NULL;

	for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
	{
		if (!cmp(key, tail->data))
		{
			tail->next->prev = tail->prev;
			tail->prev->next = tail->next;
			free(tail->data);
			free(tail);
			handle->num--;

			return 0;
		}
	}
	return -1;
}
int llist_index_del(int index, LLIST *handle)
{
		
	struct node_t *tail = NULL;

	ERRP(index < 0 || index >= handle->num, llist_index_insert option_1, goto ERR1);

	for (tail = handle->head.next; tail != &handle->head && index--; tail = tail->next)
		;	
	
	tail->next->prev = tail->prev;
	tail->prev->next = tail->next;
	free(tail->data);
	free(tail);
	handle->num--;
	
	return 0;
ERR1:
	return -1;
}

//删除所有
int llist_all_del(void *key, llist_cmp_t *cmp, LLIST *handle)
{
	struct node_t *tail = NULL;
	struct node_t *save = NULL;

	for (tail = handle->head.next; tail != &handle->head; tail = save)
	{
		save = tail->next;
		if (!cmp(key, tail->data))
		{
			//tail
			tail->next->prev = tail->prev;
			tail->prev->next = tail->next;
			free(tail->data);
			free(tail);
			handle->num--;
		}
	}
	return 0;
}

//按关键字查找
void *llist_ind(void *key, llist_cmp_t *cmp, LLIST *handle)
{
	struct node_t *tail = NULL;

	for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
	{
		if (!cmp(key, tail->data))
		{
			return tail->data;
		}
	}

	return NULL;
}
//按位置查找
void *llist_index_ind(int index, LLIST *handle)
{
	struct node_t *tail = NULL;

	ERRP(index < 0 || index >= handle->num, llist_index_insert option_1, goto ERR1);

	for (tail = handle->head.next; tail != &handle->head && index--; tail = tail->next)
		;
	return tail->data;
ERR1:
	return NULL;
}
int llist_num(LLIST *handle)
{
	return handle->num;
}
//查找所有匹配信息
LLIST *llist_find(void *key, llist_cmp_t *cmp, LLIST *handle)
{
	LLIST *ind = NULL;
	struct node_t *tail = NULL;

	ind = llist_create(handle->size);
	ERRP(ind == NULL, llist_create, goto ERR1);

	for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
	{
		if (cmp(key, tail->data) == 0)
		{
			llist_append(tail->data, ind);
		}
	}
	return ind;
ERR1:
	return NULL;
}
//排序
void llist_sort(llist_cmp_t *cmp, LLIST *handle)
{
	struct node_t *val1 = NULL, *val2 = NULL;
	void *tmp = NULL;

	tmp = (void *)malloc(handle->size);

	for (val1 = handle->head.next; val1 != &handle->head; val1 = val1->next)
	{
		for (val2 = val1->next; val2 != &handle->head; val2 = val2->next)
		{
			if (cmp(val1->data, val2->data) > 0)
			{
			#if 0
				tmp = val1->data;
				val1->data = val2->data;
				val2->data = tmp;
			#else
				memmove(tmp, val1->data, handle->size);
				memmove(val1->data, val2->data, handle->size);
				memmove(val2->data, tmp, handle->size);
			#endif
			}
		}
	}
	free(tmp);
}

//存储
void llist_store(const char *path, LLIST *handle)
{
	FILE *fp = NULL;
	int ret;
	struct node_t *tail = NULL;


	fp = fopen(path, "w");
	ERRP(NULL == fp, fopen, goto ERR1);

	//保存数据类型
	ret = fwrite(&handle->size, sizeof(handle->size), 1, fp);
	ERRP(ret != 1, fwrite size, goto ERR2);

	//保存数据大小
	ret = fwrite(&handle->num, sizeof(handle->num), 1, fp);
	ERRP(ret != 1, fwrite num, goto ERR2);

	for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
	{
		fwrite(tail->data, handle->size, 1, fp);
	}
	
	fclose(fp);
	return ;
ERR2:
	fclose(fp);
ERR1:
	return ;
}
//加载
LLIST *llist_load(const char *path)
{
	LLIST *handle = NULL;
	FILE *fp = NULL;
	int size, num;
	int ret, i;
	void *new = NULL;

	fp = fopen(path, "r");
	ERRP(fp == NULL, fopen, goto ERR1);

	ret = fread(&size, sizeof(size), 1, fp);
	ERRP(ret != 1, fread size, goto ERR2);

	ret = fread(&num, sizeof(num), 1, fp);
	ERRP(ret != 1, fread num, goto ERR2);

	handle = llist_create(size);
	ERRP(handle == NULL, llist_create, goto ERR2);

	new = (void *)malloc(size);
	ERRP(new == NULL, malloc new, goto ERR3);

	for (i = 0; i < num; i++)
	{
		ret = fread(new, size, 1, fp);
		ERRP(ret != 1, fread data, goto ERR4);

		ERRP(llist_append(new, handle) == -1, llist_aapend, goto ERR4);
	}

	fclose(fp);
	return handle;
ERR4:
	free(new);
ERR3:
	free(handle);
ERR2:
	fclose(fp);
ERR1:
	return NULL;
}
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

void llist_destroy(LLIST *handle)
{
	struct node_t *tail = NULL;
	struct node_t *save = NULL;

	for (tail = handle->head.next; tail != &handle->head; tail = save)
	{
		save = tail->next;
		free(tail->data);
		free(tail);
	}
	free(handle);
}

void llist_clean(LLIST *handle)
{
	struct node_t *tail = NULL, *save = NULL;
	
	for (tail = handle->head.next; tail = &handle->head; tail = save)
	{
		save = tail->next;
		memset(tail->data, 0, handle->size);
		free(tail->data);
		free(tail);
	}
	
	memset(handle, 0, sizeof(handle));
	handle->head.next = NULL;
	handle->head.prev = NULL;

	free(handle);

}
