#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

void queue_in(int num, int *queue, int front, int *end)
{
	queue[*end] = num;
	(*end) ++;
}

int len(int front, int end)
{
	if(end > front)
	{
		return end - front;
	}
	else
	{
		return MAX - (front - end);
	}
}

void travel(int *queue, int front, int end)
{
	int i;
	int j;

	for(i = 0, j = front; i < len(front, end); i++, j++)
	{
		if(MAX == j)
		{
			j = 0;
		}
		printf("%d ", queue[i]);
	}
}

int main(void)
{
	int queue[MAX];
	int front = 0;
	int end = 0;

	int i , num;

	for(i = 0; i < MAX ; i++)
	{
		num = i;
		queue_in(num, queue, front, &end);
	}

	travel(queue);
	putchar(10);
	return 0;
}