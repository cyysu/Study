#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <share.h>

int main(void)
{
	FILE *fp = NULL;
	char path[128];
	char mode[10];
	char ch;

	//获取文件路径
	GETLINES("please input filepath : ", path, sizeof(path));

	//获取文件模式
	GETLINES("please input filemode : ", mode, sizeof(mode));

	//打开文件 以只读模式打开
	fp = fopen(path, mode);
	ERRP(fp == NULL, "fopen failed!\n", goto ERR1);
	
	printf("success!\n");

    /*
	 *fputc('A', fp);
	 *fputc('B', fp);
	 *fputc('C', fp);
     */
	ch = fgetc(fp);
	printf("ch = %c\n", ch);

	fclose(fp);//关闭文件
	return 0;
ERR2:
	fclose(fp);
ERR1:
	return -1;
}
