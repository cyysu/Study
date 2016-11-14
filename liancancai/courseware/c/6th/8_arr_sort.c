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

void arr_sort(int arr[], int len)
{
	int i, j;

	for (i = 0; i < len; i++)
	{
		for (j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				arr[i] ^= arr[j];
				arr[j] ^= arr[i];
				arr[i] ^= arr[j];
			}
		}
	}
}

int main(void)
{
	int arr[MAX];

	srand(time(NULL));
	arr_init(arr, MAX);
	arr_show(arr, MAX);
	arr_sort(arr, MAX);
	arr_show(arr, MAX);


	return 0;
}
