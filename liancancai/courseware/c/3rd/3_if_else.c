#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int option;

	printf("==> student <==\n");
	printf("==> 1 add   <==\n");
	printf("==> 2 del   <==\n");
	printf("==> 3 find  <==\n");
	printf("==> 4 exit  <==\n");
	printf("please input option : ");
	scanf("%d", &option);

	if (option == 1)
	{
		printf("add student!\n");
	}
	else if (option == 2)
	{
		printf("del student!\n");
	}
	else if (option == 3)
	{
		printf("find student!\n");
	}
	else if (option == 4)
	{
		printf("exit student!\n");
	}
	else
	{
		printf("option error!\n");
	}
	printf("=============\n");
	switch (option)
	{
		case 1:
		/*case 10:*/
			printf("case add!\n");
			break;
		default:
			printf("case option error!\n");
			break;
		case 2:
			printf("case del!\n");
			break;
		case 3:
			printf("case find!\n");
			break;
		case 4:
			printf("case exit!\n");
			break;
	}
	return 0;
}
