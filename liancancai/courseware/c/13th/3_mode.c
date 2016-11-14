#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char ch;

	//打开文件 以只读模式打开
	//argv[1] : 表示文件路径
	//argv[2] : 表示文件模式 r r+ w w+ a a+
	fp = fopen(argv[1], argv[2]);
	if (fp == NULL)
	{
		return -1;
	}


	fputc('A', fp);

	fclose(fp);

	while(1)
		;
	printf("success!\n");

    /*
	 *ch = fgetc(fp);
	 *printf("ch = %c\n", ch);
     */

	fclose(fp);//关闭文件
	return 0;
}
