#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 3000000

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
		/*arr[i] = rand() % 100;*/
		arr[i] = rand() % 1000000;
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

int quickpass(int *a, int l, int h)
{
	int key = a[l];

	while(l < h)
	{
		while(key < a[h] && l < h)
		{
			h--;
		}
		if (l < h)
		{
			a[l] = a[h];
			l++;
		}

		while(key > a[l] && l < h)
		{
			l++;
		}
		if (l < h)
		{
			a[h] = a[l];
			h--;
		}
	}
	a[l] = key;

	return l;
}

void my_qsort(int *a, int l, int h)
{
	int m;

	if (l < h)
	{
		m = quickpass(a, l, h);//排序函数
		my_qsort(a, l, m - 1);//前半部分
		my_qsort(a, m + 1, h);//后半部分
	}
}
int main(int argc, char **argv)
{
	int arr[MAX];

	/*srand(time(NULL));*/
	init(arr);
	/*display(arr);*/
	if (argc >= 2)
	{
		my_qsort(arr, 0, MAX - 1);
	}
	else
	{
		qsort(arr, MAX, sizeof(int), cmp);
	}
	/*display(arr);*/
	return 0;
}




