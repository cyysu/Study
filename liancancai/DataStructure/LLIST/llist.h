#ifndef __LLIST_H__
#define __LLIST_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INFORMATION do{									     \
					  		printf("file %s\n", __FILE__);	 \
					  		printf("func  %s\n", __func__);  \
					  		printf("line %d\n", __LINE__);   \
					  }while(0)


#define MALLOC_ERR(condition, string, ret)  do{									\
					  								if(condition)				\
					  								{							\
					  									printf(#string"failed\n");	\
					  									INFORMATION;			\
					  									ret;					\
					  								}							\
											  }while(0)

struct node_t{
	void *data;
	struct node_t *next;
	struct node_t *prev;
};

typedef struct llist_t{
	struct node_t head;
	int num;
	int size;
}LLIST;


typedef void (cmp_op_t)(void*, void* ); 

typedef void (llist_op_t)(void *);
LLIST * llist_create(int size);

int llist_append(void *data, LLIST *handle);
int llist_travel(LLIST *handle, llist_op_t *op, int flag);


void llist_write(char *path, LLIST *handle);
LLIST *llist_read(char *path);


#endif