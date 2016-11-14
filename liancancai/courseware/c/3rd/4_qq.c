#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int username;
	int passwd;

	printf("please input username : ");
	scanf("%d", &username);

	if (317297515 == username)
	{
		printf("username true!\n");
		printf("please input username passwd : ");
		scanf("%d", &passwd);

		if (passwd == 123456)
		{
			printf("passwd success!\n");
		}
		else
		{
			printf("passwd false!\n");
		}
	}
	else
	{
		printf("username false!\n");
	}
	return 0;
}
