#include <stdio.h>
#include <string.h>
#include <stdlib.h>



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100000

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

void bubble(int *arr)//冒泡排序
{
	int i, j, tmp, k;
	for(i = MAX; i > 0; i--)
	{
		for(j = 0; j < i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
		// printf("%d :", i);
		// display(arr);
		// getchar();
	}
	// display(arr);
}

void insert(int *a)
{
	int i, j, save;
	for(i = 1; i < MAX; i++)
	{
		save = a[i];
		for(j = i; j > 0; j--)
		{
			if(save < a[j - 1])
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
int main(int argc, char *argv[])
{
	int arr[MAX];

	init(arr);
	// display(arr);
	// swap(arr);
	// display(arr);

	// bubble(arr);
	insert(arr);
	// display(arr);
	return 0;
}




