#ifndef __KEN_LLIST_H__
#define __KEN_LLIST_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//定义函数指针

typedef void (llist_op_t)(void *);
typedef int (llist_cmp_t)(void *, void *);


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


//有头 无序 循环 双向链表

//定义链表节点信息结构体
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


//函数声明
LLIST *llist_create(int size);//初始化
int llist_append(void *data, LLIST *handle);//后插
int llist_prevend(void *data, LLIST *handle);//头查
int llist_index_insert(int index, void *data, LLIST *handle);//指定位置插入

//按关键字删除
int llist_del(void *key, llist_cmp_t *cmp, LLIST *handle);
//删除所有
int llist_all_del(void *key, llist_cmp_t *cmp, LLIST *handle);
//按位置删除
int llist_index_del(int index, LLIST *handle);

//查找
void *llist_ind(void *key, llist_cmp_t *cmp, LLIST *handle);
LLIST *llist_find(void *key, llist_cmp_t *cmp, LLIST *handle);
void *llist_index_ind(int index, LLIST *handle);

int llist_num(LLIST *handle);

//排序
void llist_sort(llist_cmp_t *cmp, LLIST *handle);
int llist_store(const char *path, LLIST *handle);
LLIST *llist_load(const char *path);
//flag = 0 -> next
//flag = 1 -> prev
void llist_travel(LLIST *handle, llist_op_t *op, int flag);//遍历
void llist_destroy(LLIST *handle);//销毁
void llist_clean(LLIST *handle);//清空

#endif /*LLIST_H*/
