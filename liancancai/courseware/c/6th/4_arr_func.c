#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

//初始化
void arr_init(int arr[], int max)
{
	int i;

    /*
	 *printf("init : &arr = %p\n", &arr);
	 *
	 *printf("init : arr = %p\n", arr);
	 *printf("init : len = %d\n", sizeof(arr) / sizeof(arr[0]));
	 *printf("init : sizeof(arr) = %d\n", sizeof(arr));
	 *printf("init : sizeof(arr[0]) = %d\n", sizeof(arr[0]));
     */
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

//求最大值
int arr_max(int arr[], int len)
{
	/*printf("arr_max : ");*/
	/*arr_show(arr, max);*/
	int i;

	int max = arr[0];
	for (i = 1; i < len; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}
//最小数 反转 排序 查找 拷贝 循环左移(bit) 循环右移
int main(void)
{
	/*int a[] = {};*/

	/*printf("sizeof(a) = %d\n", sizeof(a));*/
	int arr[MAX];

	//&a a a[0]
    /*
	 *printf("main : &arr = %p\n", &arr);
	 *printf("main : arr = %p\n", arr);
	 *printf("main : len = %d\n", sizeof(arr) / sizeof(arr[0]));
	 *printf("main : sizeof(arr) = %d\n", sizeof(arr));
     */
	srand(time(NULL));
	arr_init(arr, MAX);
	arr_show(arr, MAX);
	printf("max = %d\n", arr_max(arr, MAX));

	return 0;
}
