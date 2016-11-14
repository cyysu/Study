#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BINARY_TREE_MAX 10

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

typedef struct Binary_Node_Tree_t{
	int data;
	struct Binary_Node_Tree_t *left;
	struct Binary_Node_Tree_t *right;  
}Binary_Node_Tree;

void binary_node_tree_insert(int data, Binary_Node_Tree **root)
{
	Binary_Node_Tree *new = NULL;
	Binary_Node_Tree *tail = *root;

	new = (Binary_Node_Tree *)malloc(sizeof(Binary_Node_Tree));
	ERRP(NULL == new, malloc new, goto ERR1);

	new->data = data;
	new->left = NULL;
	new->right = NULL;

	if(NULL == *root)
	{
		*root = new;
	}
	else
	{
		while(1)
		{
			if(data > tail->data)
			{
				if(tail->right != NULL)
				{
					tail = tail->right;
				}
				else
				{
					tail->right = new;
					return;
				}
			}

			if(data < tail->data)
			{
				if(tail->left != NULL)
				{
					tail = tail->left;
				}
				else
				{
					tail->left = new;
					return;
				}
			}
		}
	}

	return;
ERR1:
	return;
}

void binary_node_tree_travel(Binary_Node_Tree *root)
{
	if(NULL == root)
	{
		return;
	}

	printf("%d ", root->data);
	binary_node_tree_travel(root->left);
	binary_node_tree_travel(root->right);
}

int main(void)
{
	Binary_Node_Tree *root = NULL;
	int i;

	for(i = 0; i < BINARY_TREE_MAX; i ++)
	{
		binary_node_tree_insert(i, &root);
	}

	binary_node_tree_travel(root);
	putchar(10);

	return 0;
ERR1:
	return -1;
}
