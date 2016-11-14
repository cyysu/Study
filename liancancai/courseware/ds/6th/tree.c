#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

//定义树节点信息
struct tree_t{
	int data;
	struct tree_t *left;
	struct tree_t *right;
};


void insert(int num, struct tree_t **root)
{
	struct tree_t *new = NULL;
	struct tree_t *tail = *root;


	//新节点申请空间
	new = (struct tree_t *)malloc(sizeof(struct tree_t));
	if (NULL == new)
	{
		printf("malloc new failed!\n");
		return ;
	}

	//保存用户传的数据到新的节点信息中。
	new->data = num;
	new->left = NULL;
	new->right = NULL;

	//插入新的节点到树中。
	if (*root == NULL)
	{
		*root = new;//如果是一个空树，则把第一个数据作为根节点。
	}
	else
	{
		while(1)
		{
			if (new->data >= tail->data)
			{
				if (tail->right == NULL)
				{
					tail->right = new;
					return ;
				}
				tail = tail->right;
			}

			if (new->data < tail->data)
			{
				if (tail->left == NULL)
				{
					tail->left = new;
					return ;
				}
				tail = tail->left;
			}
		}
	}
}

void fri(struct tree_t *root)
{
	if (root == NULL)
		return ;
	printf("%d ", root->data);
	fri(root->left);
	fri(root->right);
}
void mid(struct tree_t *root)
{
	if (root == NULL)
		return ;

	mid(root->left);
	printf("%d ", root->data);
	mid(root->right);
}

void lev(struct tree_t *root)
{
	struct tree_t *queue[MAX + 1];//指针数组
	int end = 0, front = 0;

	if (root == NULL)
	{
		return ;
	}
	queue[end++] = root;

	printf("qe : ");
	while(end != front)
	{
		root = queue[front++];
		printf("%d ", root->data);

		
		if (root->left != NULL)
		{
			/*printf("%d ", root->left->data);*/
			queue[end++] = root->left;
		}
		if (root->right != NULL)
		{
			/*printf("%d ", root->right->data);*/
			queue[end++] = root->right;
		}
	}
	printf("\n");

}
void end(struct tree_t *root)
{
	if (root == NULL)
		return ;

	end(root->left);
	end(root->right);
	printf("%d ", root->data);
}

//求最大数
struct tree_t *max(struct tree_t *root)
{
	if (root == NULL)
	{
		return NULL;
	}
	while (root->right != NULL)
	{
		root = root->right;
	}
	return root;
}
struct tree_t *min(struct tree_t *root)
{
	if (root == NULL)
	{
		return NULL;
	}
	while (root->left != NULL)
	{
		root = root->left;
	}
	return root;
}
int count(struct tree_t *root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + count(root->left) + count(root->right);
}
int depth(struct tree_t *root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + (depth(root->left) >  depth(root->right) ? (depth(root->left)) : (depth(root->right))); 
}

void show(struct tree_t *root)
{
	static int lev = 0;
	int i;

	if (root == NULL)
	{
		return ;
	}
	
	lev++;
	show(root->right);
	lev--;

	for (i = 0; i < lev; i++)
	{
		printf("    ");
	}
	printf("%d\n", root->data);

	lev++;
	show(root->left);
	lev--;
}
struct tree_t *find(int key, struct tree_t *root)
{
	if (root == NULL)
	{
		return NULL;
	}
	while(1)
	{
		if (key > root->data)
		{
			if (root->right == NULL)
			{
				return NULL;
			}
			root = root->right;
		}
		else if (key < root->data)
		{
			if (root->left == NULL)
			{
				return NULL;
			}
			root = root->left;
		}
		else
		{
			return root;
		}
	}
}

void del(int key, struct tree_t **root)
{
	struct tree_t *parent = NULL;
	struct tree_t *tail = *root;
	struct tree_t *l = NULL, *r = NULL, *new = NULL;

	if (*root == NULL)
	{
		return ;
	}

	//查找当前节点，父节点
	while(1)
	{
		if (key > tail->data)
		{
			parent = tail;
			if (tail->right == NULL)
			{
				return ;
			}
			tail = tail->right;
		}
		else if (key < tail->data)
		{
			parent = tail;
			if (tail->left == NULL)
			{
				return ;
			}
			tail = tail->left;
		}
		else
		{
			break;
		}
	}
	/*printf("parent = %d\n", parent->data);*/
	/*printf("tail = %d\n", tail->data);*/

	//保存左右子树
	l = tail->left;//左子树
	r = tail->right;//右子树

	//合并左右子树到新子树中(new)
	if(tail->left == NULL && tail->right != NULL)
	{
		new = tail->right;
	}
	if (tail->left != NULL && tail->right == NULL)
	{
		new = tail->left;
	}
	if (tail->left != NULL && tail->right != NULL)
	{
		//l => r
		#if 0
		min(r)->left = l;
		new = r;
		#else
		//r => l
		max(l)->right = r;
		new = l;
		#endif
	}
	//新的子树保存到原来树中
	if (key == (*root)->data)
	{
		*root = new;	
	}
	else
	{
		if (key >= parent->data)
		{
			parent->right = new;
		}
		else
		{
			parent->left = new;
		}
	}

	//释放当前节点
	free(tail);

	return ;	
}
//最小数 节点数 树的深度 查找 删除 结构打印
int main(void)
{
	int i,num;
	struct tree_t *p = NULL;
	struct tree_t *root = NULL;//表示定义一个空树

	/*srand(getpid(NULL));*/
	for (i = 0; i < MAX; i++)
	{
		num = rand() % 100;
		printf("%d ", num);
		insert(num, &root);
	}
	printf("\n");

	printf("fri : ");
	fri(root);
	printf("\n");
	printf("mid : ");
	mid(root);
	printf("\n");
	printf("end : ");
	end(root);
	printf("\n");
	printf("");
	printf("lev : ");
	lev(root);
	printf("\n");

	printf("max = %d\n", max(root)->data);
	printf("min = %d\n", min(root)->data);
	printf("count = %d\n", count(root));
	printf("depth = %d\n", depth(root));

	printf("==============\n");
	show(root);
	printf("==============\n");
	int key;
	printf("please input del key : ");
	scanf("%d", &key);
	
	del(key, &root);
	printf("==============\n");
	show(root);
	printf("==============\n");
    /*
	 *p = find(key, root);
	 *if (p == NULL)
	 *{
	 *    printf("no find!\n");
	 *}
	 *else
	 *{
	 *    printf("find = %d\n", p->data);
	 *}
     */

	return 0;
}




