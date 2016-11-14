#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

//初始化
void arr_init(int arr[], int max)
{
	int i;
	for (i = 0; i < max; i++)
	{
		arr[i] = rand() % 100;
	}

}

//遍历
void arr_show(int arr[], int max)
{
	int i;
	for (i = 0; i < max; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int arr_find(int key, int arr[], int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		if (key == arr[i])
		{
			return arr[i];
		}
	}

	return -1;
}

int main(void)
{
	int arr[MAX];
	int key, ind;

	srand(time(NULL));
	arr_init(arr, MAX);
	arr_show(arr, MAX);
	printf("please input key : ");
	scanf("%d", &key);
	/*printf("find = %d\n", arr_find(key, arr, MAX));*/
	
	ind = arr_find(key, arr, MAX);
	if (ind == -1)
	{
		printf("no find!\n");
	}
	else
	{
		printf("find = %d\n", ind);
	}
	return 0;
}
