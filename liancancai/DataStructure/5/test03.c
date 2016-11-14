#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100000

void arr_init(int *a)
{
	int i;
	for(i = 0; i < MAX; i++)
	{
		a[i] = rand() % MAX;
	}
}

void quick_sort(int *a, int low, int high)
{
	int key;
	int low_temp = low;
	int high_temp = high;
	key = a[low];

	if(low_temp >= high_temp)
	{
		return ;
	}

loop1:
	while(high_temp >low_temp)
	{
		if(key >= a[high_temp])
		{
			a[low_temp] = a[high_temp];
			a[high_temp] = key;
			goto loop2;
		}
		else
		{
			high_temp --;
		}
	}

loop2:
	while(high_temp >low_temp)
	{
		if(key < a[low_temp])
		{
			a[high_temp] = a[low_temp];
			a[low_temp] = key;
			goto loop1;
		}
		else
		{
			low_temp++;
		}
	}
	quick_sort(a, low_temp + 1, high);
	quick_sort(a, low , low_temp - 1);

}


int main(void)
{
	int arr[MAX];

	arr_init(arr);

	quick_sort(arr, 0, MAX - 1);
	printf("quick_sort \n");
	display(arr);
	return 0;
}
