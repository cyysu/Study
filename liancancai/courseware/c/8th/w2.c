#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int m, n, i;
	char name[10][128];
	char buf[128];
	int out = 0;//退出累加器
	int count = 0;//报数器

	printf("please input m and n : ");
	scanf("%d%d", &m, &n);
	getchar();

	for (i = 0; i < m; i++)
	{
		printf("please input %d name : ", i + 1);
		fgets(buf, sizeof(buf), stdin);
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0';
		strcpy(name[i], buf);
	}

	for (i = 0; i < m; i++)
	{
		printf("%s ", name[i]);
	}
	printf("\n");

	//外围循环控制退出条件
	while(out < m)
	{
		//内层循环打印退出姓名
		
		for (i = 0; i < m; i++)
		{
			if (name[i][0] != '\0')//判断是否挂掉
				count++;
			if (count == n)
			{
				printf("%s ", name[i]);
				name[i][0] = '\0';//自杀
				count = 0;
				out++;
			}
		}
	}
	putchar(10);

	return 0;
}
