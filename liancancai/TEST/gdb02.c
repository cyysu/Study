#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int func(int n)
{
	int sum=0,i;
	for (i=0; i<n; i++)
	{
		sum+=i;
	}

	return sum;
}


void main(void)
{
	int i;
	int result[10];

	result[0] = func (0);
	result[1] = func (1);
	result[2] = func (2);
	result[3] = func (3);
	result[4] = func (4);
	
	for (i = 0; i < 5; i++)
	{
		printf("result[%d] = %d\n", i, result[i]);
	}
}