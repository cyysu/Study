#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NUM 10

void show(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	putchar(10);
}

void init(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

void insert_sort(int *a, int start, int n)
{
	int temp;
	int i, j;

	for (i = start; i < n; i++)
	{
		temp = a[i];
		for (j = i; j > 0 && temp < a[j - 1]; j--)
		{
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}

}

void shell_sort(int *a, int n)
{
	int i;

	for (i = n / 2; i > 0; i /= 2)
	{
		insert_sort(a, i, n);
	}
}


void ShellSort1(int arr[],int n)  
{  
	int gap, i, j, tmp;
    /*步长为gap，每次排序后gap减半，知道gap =1 */  
    for (gap = n/2; gap > 0; gap /= 2)  
    {  
        /*对各组进行排序*/  
        for (i = gap; i < n; ++i)  
        {  
            tmp = arr[i];  
            for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap)  
            {  
                arr[j] = arr[j - gap];  
            }  
            arr[j] = tmp;  
        }  
    }  
}  

int main(void)
{
	int arr[NUM];
	printf("shell sort\n");

	init(arr, NUM);
	show(arr, NUM);


	// insert_sort(arr, NUM);
	// show(arr, NUM);

	shell_sort(arr, NUM);	
	show(arr ,NUM);

	// ShellSort1(arr, NUM);
	// show(arr, NUM);

	return 0;
}
