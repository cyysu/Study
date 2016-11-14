#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//cp src dest
int main(int argc, char **argv)
{
	int ret;
	FILE *fpr = NULL, *fpw = NULL;
	char buf[1024];//定义缓冲区
	//src -> fread -> fopen -> argv[1]
	//dest -> write -> fopen -> argv[2]

	//1 打开文件
	fpr = fopen(argv[1], "r");
	if (fpr == NULL)
	{
		perror("fopen fread");
		return -1;
	}

	fpw = fopen(argv[2], "w");
	if (fpw == NULL)
	{
		fclose(fpr);
		perror("fopen fwrite");
		return -1;
	}

	//size	1		1024
	//num   1024	1
	//如果块中数据没有写满，则返回为0
	while((ret = fread(buf, sizeof(char), sizeof(buf), fpr)) > 0)
	{
		/*printf("ret = %d : hello!\n", ret);*/
		//buf
		fwrite(buf, sizeof(char), ret, fpw);
	}

	fclose(fpr);
	fclose(fpw);
	return 0;
}
