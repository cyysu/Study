#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

int is_full(int front, int end)
{
	if ((end + 1) % MAX == front)
		return 1;
	return 0;
}
int is_empty(int front, int end)
{
	if (front == end)
		return 1;
	return 0;
}
void qe(int num, int *queue, int front, int *end)
{
	if (is_full(front, *end))
		return ;
	queue[*end] = num;
	(*end)++;
	if (*end == MAX)
		*end = 0;
}

int de(int *queue, int *front, int end)
{
	int data;

	if (is_empty(*front, end))
		return -1;
	data =  queue[*front];
	(*front)++;
	if (*front == MAX)
		*front = 0;
	return data;
}
int len(int front, int end)
{
	if (end > front)
		return end - front;
	return MAX - (front - end);

}
void travel(int *queue, int front, int end)
{
	int i, j;

	for (i = 0, j = front; i < len(front, end); i++, j++)
	{
		if (j == MAX)
			j = 0;
		printf("%d ", queue[j]);
	}
	printf("\n");
}
int main(void)
{
	int i, num;
	int queue[MAX];//定义队列
	int front = 0, end = 0;//定义队头 队尾

	for (i = 0; i < MAX + 3; i++)
	{
		num = rand() % 100;
		printf("%d ", num);
		//入队
		qe(num, queue, front, &end);
	}
	printf("\n");


	printf("one = %d\n", de(queue, &front, end));
	printf("two = %d\n", de(queue, &front, end));
	printf("three = %d\n", de(queue, &front, end));
	printf("four = %d\n", de(queue, &front, end));
	qe(100, queue, front, &end);
	printf("five = %d\n", de(queue, &front, end));
	qe(101, queue, front, &end);
	qe(102, queue, front, &end);
	qe(103, queue, front, &end);
	qe(104, queue, front, &end);
	qe(105, queue, front, &end);
	qe(106, queue, front, &end);

	for (i = 0; i < MAX + 3; i++)
	{
		printf("%d ", de(queue, &front, end));
	}
	printf("\n");
	/*travel(queue, front, end);*/
	return 0;
}
