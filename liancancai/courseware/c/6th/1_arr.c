#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count = 0;

// stack 12M
void stack_size(void)
{
	char buf[1024];//1k

	printf("count = %d\n", count++);
	stack_size();
}
int main(void)
{
	int a;//4
	int i;
	int arr[10] = {0, 123, [5] = 4, [0] = 6, 1122};//40  定义数组变量

	/*arr = {1,2,3,4,5,6};*/


	for (i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100;
	}
	printf("arr[10] = %d\n", arr[1]);

	/*stack_size();*/
	printf("arr[0] = %d\n", arr[0]);
	printf("arr[1] = %d\n", arr[1]);
	
	/*arr[0] = 123;*/
	for (a = 0; a < 10; a++)
	{
		printf("arr[%d] = %d\n", a, arr[a]);
	}
	a = 5;

	printf("sizeof(int) = %d\n", sizeof(int));
	printf("sizeof(arr) = %d\n",sizeof(arr));//空间大小

	return 0;
}
