#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 128

void push(char data, char *stack, int *top)
{
	stack[*top] = data;
	(*top)++;
}

char pop(char *stack, int *top)
{
	(*top)--;
	return stack[*top];
}

void travel(char *stack, int top)
{
	int i;
	for (i = 0; i < top; i++)
	{
		putchar(stack[i]);
	}
	printf("\n");
}
int main(void)
{
	int top = 0;
	int i;
	char stack[MAX];
	char buf[128];

	printf("please input string : ");
	fgets(buf, sizeof(buf), stdin);
	if (buf[strlen(buf) - 1] == '\n')
		buf[strlen(buf) - 1] = '\0';

	for (i = 0; i < strlen(buf); i++)
	{
		if (buf[i] == '#')
		{
			pop(stack, &top);
		}
		else if (buf[i] == '@')
		{
			push('\n', stack, &top);
		}
		else
		{
			push(buf[i], stack, &top);
		}
	}

	travel(stack, top);

	return 0;
}
