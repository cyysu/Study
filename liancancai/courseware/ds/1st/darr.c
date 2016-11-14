#include "darr.h"

//初始化
DARR *darr_create(int size)
{
	DARR *handle = NULL;

	handle = (DARR *)malloc(sizeof(DARR));
	ERRP(NULL == handle, malloc handle, goto ERR1);

	handle->data = NULL;
	handle->size = size;
	handle->num = 0;

	return handle;
ERR1:
	return NULL;
}
//尾插
void darr_append(void *data, DARR *handle)
{
	//申请数据空间
	void*new = NULL;

	ERRP(data == NULL, darr_append option, goto ERR1);

	new = (void *)malloc(handle->size * (handle->num + 1));
	ERRP(NULL == new, malloc new, goto ERR1);

	//添加数据到空间地址中
	memcpy(new, handle->data, handle->size * handle->num);
	free(handle->data);
	/*new[*count] = cls;*/
	memcpy(new + handle->num * handle->size, data, handle->size);
	handle->data = new;
	handle->num++;
	/*prev = new;*/
	return ;
ERR1:
	return ;
}
//头插

void darr_prevend(void *data, DARR *handle)
{
	void *new = NULL;

	ERRP(data == NULL, darr_prevend option, goto ERR1);

	new = (void *)malloc(handle->size * (handle->num + 1));
	ERRP(NULL == new, malloc new, goto ERR1);

	memcpy(new, data, handle->size);
	memcpy(new + handle->size, handle->data, handle->size * handle->num);
	free(handle->data);
	handle->data = new;
	handle->num++;

	return ;
ERR1:
	return ;
}

//指定位置插入
void darr_insert(int index, void *data, DARR *handle)
{
	void *new = NULL;

	/*ERRP(index < 0 || index >= handle->num, darr_insert option, goto ERR1);*/
	if (index < 0)
	{
		index = 0;
	}
	if (index >= handle->num)
	{
		index = handle->num;
	}

	ERRP(data == NULL, darr_prevend option, goto ERR1);

	new = (void *)malloc(handle->size * (handle->num + 1));
	ERRP(NULL == new, malloc new, goto ERR1);
	
	//先存放handle->data前半部分
	memcpy(new, handle->data, handle->size * index);
	//拷贝新的收据
	memcpy(new + handle->size * index, data, handle->size);
	//拷贝后半部分
	memcpy(new + handle->size * (index + 1), handle->data + handle->size * index, handle->size * (handle->num - index));
	free(handle->data);
	handle->data = new;
	handle->num++;

	return ;
ERR1:
	return ;
}

//按关键字删除， 删除查找到第一个匹配数据信息
void darr_del(void *key, DARR *handle, darr_cmp_t *cmp)
{
	int i;
	void *new = NULL;
	ERRP(key == NULL, darr_del option, goto ERR1);

	for (i = 0; i < handle->num; i++)
	{
		if (cmp(key, handle->data + i * handle->size) == 0)
		{
			new = (void *)malloc(handle->size * (handle->num - 1));
			ERRP(new == NULL, malloc new, goto ERR1);

			memcpy(new, handle->data, handle->size * i);
			memcpy(new + handle->size * i, handle->data + handle->size * (i + 1), handle->size * (handle->num - i - 1));
			free(handle->data);
			handle->data = new;
			handle->num--;

			return ;
		}
	}
	return ;
ERR1:
	return ;
}

//删除所有匹配信息
void darr_alldel(void *key, DARR *handle, darr_cmp_t *cmp)
{
	int i;
	void *new = NULL;

	ERRP(key == NULL, darr_alldel option, goto ERR1);

	for (i = 0; i < handle->num; i++)
	{
		if (cmp(key, handle->data + i * handle->size) == 0)
		{
			new = (void *)malloc(handle->size * (handle->num - 1));
			ERRP(new == NULL, malloc new, goto ERR1);

			memcpy(new, handle->data, handle->size * i);
			memcpy(new + handle->size * i, handle->data + handle->size * (i + 1), handle->size * (handle->num - i - 1));
			free(handle->data);
			handle->data = new;
			handle->num--;
			i--;
		
		}
	}
	return ;
ERR1:
	return ;
}
//查找所有匹配信息
DARR *darr_find(void *key, DARR *handle, darr_cmp_t *cmp)
{
	int i;
	DARR *ind = NULL;
	
	ind = darr_create(handle->size);
	ERRP(ind == NULL, darr_create, goto ERR1);

	for (i = 0; i < handle->num; i++)
	{
		if (cmp(key, handle->data + i * handle->size) == 0)
		{
			darr_append(handle->data + i * handle->size, ind);
		}
	}
	
	return ind;
ERR1:
	return ;
}
//指定位置删除
void darr_index_del(int index, DARR *handle)
{
	void *new = NULL;

	ERRP(index < 0 || index >= handle->num, darr_index_del option, goto ERR1);

	new = (void *)malloc(handle->size * (handle->num - 1));
	ERRP(NULL == new, malloc, goto ERR1);

	//拷贝handle->data前半部分到new
	memmove(new, handle->data, handle->size * index);
	//拷贝handle->data后半部分到new
	memmove(new + handle->size * index, handle->data + handle->size * (index + 1), handle->size * (handle->num - index - 1));
	free(handle->data);
	handle->data = new;
	handle->num--;

	return ;
ERR1:
	return ;
}
//求数据长度
int darr_num(DARR *handle)
{
	return handle->num;
}


//按关键字查找 从前到后
void *darr_ind(void *key, DARR *handle, darr_cmp_t *cmp, int flag)
{
	int i;
	void *tmp = NULL;
	
	for (i = 0; i < handle->num; i++)
	{
		if (!cmp(key, handle->data + i * handle->size))
		{
			if (flag == 0)
			{
				return handle->data + i * handle->size;
			}
			else
			{
				tmp = handle->data + i * handle->size;
			}
		}
	}

	return tmp;
}

void *darr_index_ind(int index, DARR *handle)
{
	ERRP(index < 0 || index >= handle->num, darr_index_ind option, goto ERR1);

	return handle->data + handle->size * index;
ERR1:
	return NULL;
}

//排序
void darr_sort(darr_cmp_t *cmp, DARR *handle, int flag)
{
	int i, j;
	void *tmp = NULL;

	tmp = (void *)malloc(handle->size);
	ERRP(NULL == tmp, malloc, goto ERR1);

	for (i = 0; i < handle->num; i++)
	{
		for (j = i + 1; j < handle->num; j++)
		{
			if (cmp(handle->data + handle->size * i, handle->data + handle->size * j) > 0)
			{
				memcpy(tmp, handle->data + i * handle->size, handle->size);
				memcpy(handle->data + handle->size * i, handle->data + handle->size * j, handle->size);
				memcpy(handle->data + handle->size * j, tmp, handle->size);
			}
		}
	}
	return ;
ERR1:
	return ;
}
//存储
//fputc fputs fwrite fscanf
void darr_store(const char *path, DARR *handle)
{
	FILE *fp = NULL;
	int ret;

	fp = fopen(path, "w");
	ERRP(NULL == fp, fopen, goto ERR1);

	//保存数据类型
	ret = fwrite(&handle->size, sizeof(handle->size), 1, fp);
	ERRP(ret != 1, fwrite size, goto ERR2);

	//保存数据长度
	ret = fwrite(&handle->num, sizeof(handle->num), 1, fp);
	ERRP(ret != 1, fwrite num, goto ERR2);

	//保存数据
	ret = fwrite(handle->data, handle->size, handle->num, fp);
	ERRP(ret != handle->num, fwrite, goto ERR2);

	fclose(fp);
	return ;
ERR2:
	fclose(fp);
ERR1:
	return ;
}
//加载
DARR *darr_load(const char *path)
{
	FILE *fp = NULL;
	int size, num, ret;
	DARR *handle = NULL;

	void *buf = NULL;

	fp = fopen(path, "r");
	ERRP(fp == NULL, fopen, goto ERR1);

	//获取数据类型
	ret = fread(&size, sizeof(size), 1, fp);
	ERRP(ret != 1, fread size, goto ERR2);

	//获取数据长度
	ret = fread(&num, sizeof(num), 1, fp);
	ERRP(ret != 1, fread num, goto ERR2);
	
	/*printf("size = %d num = %d\n", size, num);*/
	//申请handle空间
	handle = darr_create(size);
	ERRP(NULL == handle, darr_create, goto ERR2);
	handle->num = num;

	//数据申请空间
	handle->data = (void *)malloc(size * num);
	ERRP(handle->data == NULL, malloc data, goto ERR3);

	//获取数据
	ret = fread(handle->data, size, num, fp);
	ERRP(ret != num, fread, goto ERR4);

	fclose(fp);
	return handle;
ERR4:
	free(handle->data);
ERR3:
	free(handle);
ERR2:
	fclose(fp);
ERR1:
	return NULL;
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

//销毁函数
void darr_destroy(DARR *handle)
{
	free(handle->data);
	free(handle);
}

