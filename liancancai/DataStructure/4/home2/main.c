#include "stack.h"


struct cls_t{
	char name[128];
	int id;
	int age;
	char sex;
};


void stack_ls(void *data)
{
	struct cls_t *cls = (struct cls_t *)data;
	printf("name = %s, id = %d, age = %d, sex = %c\n", cls->name, cls->age, cls->id, cls->sex);

}

void stack_ls_int(void *data)
{
	int *i = (int *)data;
	printf("%d\n", *i);
}

void stack_ls_char(void *data)
{
	printf("%c", *(char *)data);
}

void nbl(char *buf, STACK *stack)
{
	int len;
	int flag = 1;
	int i, count;
	int temp_num = 0, temp_char = 0;

	len = strlen(buf);

	for(i = 0, count = 0; count < len; i++)
	{
		if(1 == flag)
		{	
			if(buf[i] > '0' && buf[i] < '9')
			{
				stack_push(buf + i, stack);
				flag = 2;
				count ++;
				temp_num = i ;
				i = temp_char;
			}
		}
		else
		{
			if(buf[i] == '+' || buf[i] == '-' || buf[i] == '*' || buf[i] ==  '/' || buf[i] == '%')
			{
				stack_push(buf + i, stack);
				flag = 1;
				count ++;
				temp_char = i;
				i = temp_num;
			}
		}
	}
}

int stack_option(int a, int b, char c)
{
	if('+' == c)
	{
		return a + b;
	}
	else if('-' == c)
	{
		return a - b;
	}
	else if('*' == c)
	{
		return a * b;
	}
	else if('/' == c)
	{
		return a / b;
	}
	else 
	{
		return a % b;
	}

}

int char_to_int(char c)
{
	return (c - '0');
}

void stack_nbl(STACK *stack)
{
	int i;
	int num1 ,num2;
	char option;
	int result;
	int len;

	len = stack->top;

	i = 1;
	result = char_to_int(*(char*)stack_pop(stack));
	while(i < len)
	{
		num1 = result;

		option = (*(char*)stack_pop(stack));

		num2 = char_to_int(*(char*)stack_pop(stack));

		result = stack_option(num1, num2, option);

		printf("%d %c %d = %d\n", num1, option, num2, result);

		i += 2;
	}
}

int main(void)
{
	STACK *stack1 = NULL, *stack2 = NULL;
	char buf[128];
	int i, len;

	stack1 = stack_create(MAX, sizeof(char));
	ERRP(NULL == stack1, stack_create stack1, goto ERR1);

	stack2 = stack_create(MAX, sizeof(char));
	ERRP(NULL == stack2, stack_create stack2, goto ERR2);
	
	printf("请输入一个逆波兰序列 :");
	fgets(buf, sizeof(buf), stdin);

	if(buf[strlen(buf) - 1] == '\n')
	{
		buf[strlen(buf) - 1] = '\0';
	}

	printf("buf = %s\n", buf);

	len = strlen(buf);

	nbl(buf, stack1);//将输入的字符串存入stack1中并整理好顺序

	//输出整理好的stack1
	printf("stack = ");
	stack_travel(stack1, stack_ls_char);
	putchar(10);

	//将stack1 出栈 并存到stack2中，实现字符串的反转 
	for(i = 0; i < len; i++)
	{
		stack_push(stack_pop(stack1), stack2);
	}

	stack_destroy(stack1);

	stack_nbl(stack2);//打印执行过程

	stack_destroy(stack2);

	return 0;
ERR2:
	free(stack1);
ERR1:
	return 0;
}