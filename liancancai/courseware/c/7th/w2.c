#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 12

void init(int a[])
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		a[i] = rand() % 10;
	}
}
void show(int a[])
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		printf("%d ", a[i]);
	}
	putchar(10);
}
int main(void)
{
	int a[MAX];
	int i, j;
	int count;
	int max,sec;

	max = sec = -1;

	srand(time(NULL));
	init(a);
	show(a);

	for (i = 0; i < MAX; i++)
	{
		for (j = 0, count = 0; j < MAX; j++)
		{
			if (a[i] == a[j])
			{
				count++;
			}
		}
		if (count == 1)
		{
			printf("%d ", a[i]);
			if (max < a[i])
			{
				sec = max;
				max = a[i];
			}
			else if (sec < a[i])
			{
				sec = a[i];
			}
		}
	}
	printf("\n");
	printf("sec = %d\n", sec);

	return 0;
}
