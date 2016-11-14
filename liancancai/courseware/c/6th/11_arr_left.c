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

void arr_left(int bit, int arr[], int len)
{
	int i, j;
	int save;
	
	for (j = 0; j < bit; j++)
	{
		save= arr[0];

		for (i = 0; i < len - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[len - 1] = save;
	}
}

int main(void)
{
	int arr[MAX];
	int bit;

	srand(time(NULL));
	arr_init(arr, MAX);
	arr_show(arr, MAX);
	printf("please input bit : ");
	scanf("%d", &bit);
	arr_left(bit, arr, MAX);
	arr_show(arr, MAX);


	return 0;
}
