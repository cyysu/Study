/**
 * @Author:      lcc
 * @DateTime:    2016-11-23 08:42:16
 * @Description: 插入排序法 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 20

void show(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


void arry_init(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		a[i] = rand() % NUM;
	}
}

void insert_sort(int *arr, int n)
{
	int i, j;
	int temp;

	for (i = 1; i < n; i++)
	{
		temp = arr[i];
		for(j = i; j > 0 && arr[j - 1] > temp; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}

int main(void)
{
	int arr[NUM];

	arry_init(arr, NUM);
	show(arr, NUM);

	insert_sort(arr, NUM);
	show(arr, NUM);
	return 0;
}
