#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 128


int push(char data, char *stack, int * top)
{
	stack[*top] = data;
	(*top) ++;

	return 0;
}

int pop(char *stack, int *top)
{
	(*top) --;
	// printf("%c", stack[*top]);
	return 0;
}


void travel(char *stack, int top)
{
	int i;

	for (i = 0; i < top; i++)
	{
		printf("%c", stack[i]);
	}
	printf("\n");
}

int main(void)
{
	char stack1[MAX], stack2[MAX];
	int top1 = 0, top2 = 0;
	int i;
	char buf[] = "hea#lll#o@zhaken###ngsin##an@";

	for(i = 0; i < strlen(buf); i++)
	{
		if('#' == buf[i])
		{
			pop(stack1, &top1);
		}
		else if('@' == buf[i])
		{
			push('\n' ,stack1, &top1);
		}
		else
		{
			push(buf[i], stack1, &top1);
		}
	}

	travel(stack1, top1);

	return 0;
}