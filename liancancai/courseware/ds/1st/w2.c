#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//grep key filename
//key -> argv[1]
//filename -> argv[2] -> r -> fgets -> strstr -> vt
int main(int argc, char **argv)
{
	FILE *fp = NULL;
	char buf[128];
	char tmp[128] = {};//临时变量，用来保存关键字以外字符串
	int count = 0;
	char *s = NULL, *p = NULL;

	fp = fopen(argv[2], "r");
	if (NULL == fp)
	{
		printf("fopen fialed!\n");
		return -1;
	}

	while(fgets(buf, sizeof(buf), fp) != NULL)
	{
		count++;//统计行号
		if (strstr(buf, argv[1]) != NULL)//满足则打印
		{
			printf("%d :", count);
		}
		s = buf;
		//s指向字符串首地址，定义s为了偏移字符串
		while((p = strstr(s, argv[1])) != NULL)
		{
			/*strncpy(tmp, s, p - s);*/
			snprintf(tmp, p - s + 1, "%s", s);//保存关键字前面字符串
			printf("%s", tmp);
			printf("\033[31m%s\033[0m", argv[1]);
			s = p + strlen(argv[1]);//重新指向关键字后面字符串
		}
		if (s != buf)//判断s是否等于buf首地址，如果相等，则这一行没有关键字，反之则打印。
			printf("%s", s);
		/*getchar();*/
	}
	return 0;
}
