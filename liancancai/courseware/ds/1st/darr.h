#ifndef __KEN_DARR_H__
#define __KEN_DARR_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


//函数指针
typedef void (darr_op_t)(void *);
typedef int (darr_cmp_t)(void *, void *);


//抽象数据类型
typedef struct darr_t{
	void *data;//表示所有的数据
	int size;//表示类型
	int num;//表示空间大小
}DARR;

//函数声明
//初始化函数
DARR *darr_create(int size);
//插入函数 尾插
void darr_append(void *data, DARR *handle);
//头插
void darr_prevend(void *data, DARR *handle);
//遍历函数
void darr_travel(DARR *handle, darr_op_t *op);
//指定位置插入
void darr_insert(int index, void *data, DARR *handle);

//删除：删除第一个匹配信息
void darr_del(void *key, DARR *handle, darr_cmp_t *cmp);
//删除所有匹配信息
void darr_alldel(void *key, DARR *handle, darr_cmp_t *cmp);
//指定位置删除
void darr_index_del(int index, DARR *handle);

//求数据长度
int darr_num(DARR *handle);

//查找 查找匹配关键字
//flag = 0 => 从前到后 strchr
//flag = 1 => 从后到前 strrchr
void *darr_ind(void *key, DARR *handle, darr_cmp_t *cmp, int flag);
//查找所有匹配信息
DARR *darr_find(void *key, DARR *handle, darr_cmp_t *cmp);
//按位置查找
void *darr_index_ind(int index, DARR *handle);

//修改
//排序
// flag = 0 little -> big
// flag = 1 big -> little
void darr_sort(darr_cmp_t *cmp, DARR *handle, int flag);
//存储
void darr_store(const char *path, DARR *handle);
//加载
DARR *darr_load(const char *path);

//销毁函数
void darr_destroy(DARR *handle);

#endif /*KEN_DARR_H*/
