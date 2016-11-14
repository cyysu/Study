#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

//初始化
void init(int *arr)
{
	int i ;

	for (i = 0; i < MAX; i++)
	{
		/*arr[i] = rand() % 100;*/
		arr[i] = rand() % 100;
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
//选择排序
//取出一个数据跟后面所有的数据比较，如果满足条件，则保存最小值的下标
void my_select(int *a)
{
	int i, j;
	int t;//保存最小值下标
	int tmp;

	for (i = 0; i < MAX; i++)
	{
		t = i;
		for (j = i + 1; j < MAX; j++)
		{
			if (a[t] > a[j])
			{
				t = j;
			}
		}
		#if 0
		tmp = a[i];
		a[i] = a[t];
		a[t] = tmp;
		#else
		a[i] ^= a[t];
		a[t] ^= a[i];
		a[i] ^= a[t];
		display(a);
		getchar();
		#endif
	}
}

int main(void)
{
	int arr[MAX];
	int a = 2, b = 2;

	a ^= b;
	b ^= a;
	a ^= b;

	printf("a = %d b = %d\n", a, b);

	/*srand(time(NULL));*/
	init(arr);
	display(arr);
	my_select(arr);
	display(arr);
	return 0;
}




