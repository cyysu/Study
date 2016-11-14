#ifndef __KEN_STACK_H__
#define __KEN_STACK_H__

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


//抽象数据类型 顺序表实现 => 数栈
//链表实现 => 链栈

//抽象栈数据类型
typedef struct stack_t{
	void *data;//表示栈
	int max;//表示栈大小
	int top;//表示栈顶元素
	int size;//表示数据类型
}STACK;

//定义函数指针
typedef void (*stack_op_t)(void *);


//函数声明
STACK *stack_create(int max, int size);//初始化栈
int stack_is_full(STACK *handle);//判断是否是满栈
int stack_is_empty(STACK *handle);//判断是否是空栈
void stack_push(void *data, STACK *handle);//压栈
void *stack_pop(STACK *handle);//弹栈
void stack_store(const char *path, STACK *handle);//存储
STACK *stack_load(const char *path);//加载
void stack_travel(STACK *handle, stack_op_t op);//遍历
void stack_destroy(STACK *handle);//销毁







#endif //
