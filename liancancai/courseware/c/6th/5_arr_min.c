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

int arr_min(int arr[], int len)
{
	int i;
	int min = arr[0];

	for (i = 1; i < len; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
	}
	return min;
}

int main(void)
{
	int arr[MAX];

	srand(time(NULL));
	arr_init(arr, MAX);
	arr_show(arr, MAX);
	printf("min = %d\n", arr_min(arr, MAX));

	return 0;
}
