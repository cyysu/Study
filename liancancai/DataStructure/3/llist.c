#include "llist.h"

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
// //实现后插
// int llist_append(void *data, LLIST *handle)
// {
// 	struct node_t *new = NULL;

// 	new = (struct node_t *)malloc(sizeof(struct node_t));
// 	ERRP(NULL == new, malloc new, goto ERR1);

// 	new->data = (void *)malloc(handle->size);
// 	ERRP(new->data == NULL, malloc new->data, goto ERR2);

// 	memcpy(new->data, data, handle->size);
// 	//用户传递数据保存到节点信息中
// 	//====================
// 	//把new节点信息插入到链表handle->head中

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

int llist_append(void *data, LLIST *handle)
{
	struct node_t *new;

	new = (struct node_t *)malloc(sizeof(struct node_t));
	ERRP(NULL == new, malloc new failed, goto ERR1);

	new->data = (void *)malloc(handle->num);
	ERRP(NULL == new->data, malloc new->data, goto ERR2);
	return 1;

	memcpy(new->data, data, handle->size);

	new->next = &handle->head;
	new->prev = handle->head.prev;
	handle->head.prev->next = new;
	handle->head.prev = new;
	handle->num ++;

	return 1;

ERR2:
	free(new);
ERR1:
	return -1;
}

//头插
int llist_prevend(void *data, LLIST *handle)
{
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
