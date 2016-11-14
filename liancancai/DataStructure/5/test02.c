#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

int cmp(const void *d1, const void *d2)
{
	return *(int *)d1 - *(int *)d2;
}
//初始化
void init(int *arr)
{
	int i ;

	for (i = 0; i < MAX; i++)
	{
		arr[i] = rand() % 100;
	}
}

//遍历
void display(int *arr)
{
	int i;

	for (i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//交换排序，是选择排序一个变种
//取出一个数据数据，跟后面所有数据比较，如果满足条件，则交换
void swap(int *arr)
{
	int i, j, tmp, k;

	for (i = 0; i < MAX; i++)
	{
		for (j = i + 1; j < MAX; j++)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
        /*
		 *printf("%d : ", i + 1);
		 *display(arr);
		 *getchar();
         */
	}
}
//冒泡排序：
//相邻的两个数比较，小数上浮 大数下沉
void bubble(int *a)
{
	int i, j;

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				a[j] ^= a[j + 1];
				a[j + 1] ^= a[j];
				a[j] ^= a[j + 1];
			}
		}
	}
}
//选择排序
//取出一个数据跟后面所有的数据比较，如果满足条件，则保存最小值的下标
void my_select(int *a)
{
	int i, j;
	int t;//保存最小值下标

	for (i = 0; i < MAX; i++)
	{
		t = i;
		for (j = i + 1; j < MAX; j++)
		{
			if (a[t] > a[j])
			{
				t = j;
			}
		}
		if (t != i)
		{
			a[i] ^= a[t];
			a[t] ^= a[i];
			a[i] ^= a[t];
		}
		/*display(a);*/
	}
}

//插入排序
//从第二个数据开始，从后往前查找，满足条件则把前一个数据给后一个数据
void insert(int *a)
{
	int i, j, save;

	for (i = 1; i < MAX; i++)
	{
		save = a[i];
		for (j = i; j > 0; j--)
		{
			if (save < a[j - 1])
			{
				a[j] = a[j - 1];
			}
			else
			{
				break;
			}
		}
		a[j] = save;
	}
}

//一般查找法
int find(int key, int *a)
{
	int i;

	for (i = 0; i < MAX; i++)
	{
		if (key == a[i])
		{
			return a[i];
		}
	}

	return -1;
}

int my_bsearch(int key, int *a)
{
	int i, prev_i, flag = 0;
	i = 0;
	prev_i = i;
	i = MAX / 2;


	if(key != a[i])
	{
		if(key < a[i])
		{
			i = (prev_i + i) / 2;
			prev_i = i;
		}
		else
		{
			i = (MAX + i) / 2;
		}
	}

	
}
int main(void)
{
	int arr[MAX];
	int key;
	int ind;
	int *p = NULL;

	init(arr);
	insert(arr);
	display(arr);

	printf("please input find number : ");
	scanf("%d", &key);
    

	p = bsearch(&key, arr, MAX, sizeof(int), cmp);
	// p = my_bsearch(&key, arr, MAX, sizeof(int), cmp);
	if (p == NULL)
	{
		printf("no find!\n");
	}
	else
	{
		printf("ind = %d\n", *(int *)p);
	}
	return 0;
}




