#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int x, y;
	char buf[128];
	int i;


	while(1)
	{
		for (i = 0; i < 100; i++)
		{
			printf("\033[%d;%dH", rand() % 20, rand() % 68);
			printf("\033[%dmhello!\033[0m", rand() % 8 + 30);
		}
		fflush(NULL);
		usleep(200000);
	}
	system("clear");
	printf("\033[?25l");
	while(1)
	{
		printf("\033[10;15H");
		printf("display : \033[K\033[s");
		scanf("%s", buf);

		printf("0\033[5;15H");
		printf("show : %s\n\033[u", buf);
		getchar();
		getchar();
	}
	printf("please input x and y : ");
	scanf("%d%d", &x, &y);
	system("clear");
	printf("\033[%d;%dH", x, y);

	printf("\033[4m\033[31mh\033[32me\033[33ml\033[34ml\033[35mo!\033[0m\n");
	printf("\033[32;41mworld\033[0m\n");
	printf("\033[2Atest!\n");
	getchar();
	return 0;
}
