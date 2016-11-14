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

void arr_rever(int arr[], int len)
{
	int i, tmp;

	for (i = 0; i < len / 2; i++)
	{
		tmp = arr[i];
		arr[i] = arr[len - 1 - i];
		arr[len - 1 - i] = tmp;
	}
}
int main(void)
{
	int arr[MAX];

	srand(time(NULL));
	arr_init(arr, MAX);
	arr_show(arr, MAX);
	arr_rever(arr, MAX);
	arr_show(arr, MAX);

	/*printf("min = %d\n", arr_min(arr, MAX));*/

	return 0;
}
