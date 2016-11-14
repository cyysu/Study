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

void arr_copy(int dest[], int src[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		dest[i] = src[i];
	}
}

int main(void)
{
	int arr[MAX];
	int dest[MAX] = {};

	srand(time(NULL));
	arr_init(arr, MAX);
	arr_show(arr, MAX);
	arr_copy(dest + 4, arr + 2, 5);
	arr_show(dest, MAX);

	return 0;
}
