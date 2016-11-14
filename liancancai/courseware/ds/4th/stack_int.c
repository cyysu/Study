#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//案例 int

//定义栈的大小
#define MAX 10

//判断是否是满栈
int is_full(int top)
{
	if (top == MAX)
		return 1;
	return 0;
}
//判断是否是空栈
int is_empty(int top)
{
	if (top == 0)
		return 1;
	return 0;
}
//压栈
int push(int data, int *stack, int *top)
{
	if (is_full(*top))
		return -1;

	stack[*top] = data;
	(*top)++;
	return 0;
}

//弹栈
int pop(int *stack, int *top)
{
	if (is_empty(*top))
		return -1;
	(*top)--;
	return stack[*top];
}
void travel(int *stack, int top)
{
	int i;

	for (i = 0; i < top; i++)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
}
int main(void)
{
	//定义栈
	int stack[MAX];
	//栈顶元素
	int top = 0;
	//定义临时变量，接受用户数据
	int num, i;
	int ret;

	for (i = 0; i < MAX + 2; i++)
	{
		num = rand() % 100;
		printf("%d ", num);
		//压栈函数
		push(num, stack, &top);
	}
	printf("\n");
	//遍历栈
	travel(stack, top);

	printf("one = %d\n", pop(stack, &top));
	printf("stack[9] = %d\n", stack[9]);

	printf("two = %d\n", pop(stack, &top));
	push(100, stack, &top);
	for (i = 0; i < MAX; i++)
	{
		ret = pop(stack, &top);
		if (ret == -1)
		{
			printf("空 ");
		}
		else
		{
			printf("%d ", ret);
		}
		/*printf("%d ", pop(stack, &top));*/
	}
	printf("\n");
	return 0;
}
