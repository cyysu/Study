#ifndef __SELECT_COURSE_SIMPLE_H__
#define __SELECT_COURSE_SIMPLE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INFORMATION   do{					\
		printf("file: %s\n", __FILE__);		\
		printf("func: %s\n", __func__);		\
		printf("line: %d\n", __LINE__);		\
}while(0)

#define ERRP(condition, string, ret) do{	\
		if(condition)						\
		{									\
			printf(#string" failed\n");		\
			INFORMATION;					\
			ret;							\
		}									\
}while(0)

typedef void (llist_op_t)(void *);

struct  node_t{
	struct node_t *prev;
	struct node_t *next;
	void *data;
};

typedef struct llist_t{
	int size;
	int num;
	struct node_t head;
}LLIST;

LLIST *llist_create(int size);
void llist_add(void *data, LLIST *handle);
void llist_travel(LLIST *handle, llist_op_t *op);


#endif