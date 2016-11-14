#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <share.h>

int main(void)
{
	FILE *fp = NULL;
	char path[128];
	char ch;

	//获取文件路径
	GETLINES("please input filepath : ", path, sizeof(path));

	//打开文件 以只读模式打开
	fp = fopen(path, "r");
	ERRP(fp == NULL, "fopen failed!\n", goto ERR1);
	
	printf("success!\n");

    /*
	 *int ret;
	 *ret = fputc('A', fp);
	 *printf("EOF = %d\n", EOF);
	 *ERRP(ret == EOF, "fputc failed!\n", goto ERR2);
     */

	//循环获取文件内容
	system("clear");
	while((ch = fgetc(fp)) != EOF)
	{
		putchar(ch);
		/*putch(ch, rand() % 7 + 31, 10);*/
		usleep(50000);
		fflush(NULL);
	}
	ERRP(ch == EOF, "fgetc failed!\n", goto ERR2);

	printf("ch = %c\n", ch);
	fclose(fp);//关闭文件
	return 0;
ERR2:
	fclose(fp);
ERR1:
	return -1;
}
