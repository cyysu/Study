#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//冒泡排序
#define NUM 20

void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

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

void bubble_sort(int *arr, int n)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

int main(int argc, char **argv)
{         
	int arr[NUM];
	int i;

	arry_init(arr, NUM);
	show(arr, NUM);

	bubble_sort(arr, NUM);
	show(arr, NUM);
 	return 0;
}
