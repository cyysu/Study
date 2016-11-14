#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int num, key;

	srand(time(NULL));
	num = rand() % 100;

	while(1)
	{
		printf("please input key :");
		scanf("%d", &key);

		if (key > num)
		{
			printf("little!\n");
		}
		else if (key < num)
		{
			printf("big!\n");
		}
		else
		{
			printf("success!!!!!\n");
			break;
		}
	}
	return 0;
}
