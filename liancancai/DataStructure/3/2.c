#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num;
	int *new = NULL;
	int * prev = NULL;
	int count = 0;
	int i;
	while(1)
	{
		printf("please input num:");
		scanf("%d", &num);

		if(-1 == num)
		{
			break;
		}

		new = (int *)malloc(sizeof(int) * (count + 1));
		if(NULL == new)
		{
			return ;
		}
	
		memcpy(new, prev, sizeof(int) * count);
		free(prev);
		new[count] = num;
		prev = new;
		count ++;
	}

	for(i = 0; i < count; i++)
	{
		printf("new[%d] = %d\n", i, new[i]);
	}
}