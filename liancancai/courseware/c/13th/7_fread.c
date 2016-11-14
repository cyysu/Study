#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp = NULL;
	char buf[128] = {};
	int ret;

	fp = fopen(argv[1], "w");
	if (fp == NULL)
	{
		perror("fopen");
		return -1;
	}

	
	strcpy(buf, argv[2]);

	/*ret = fwrite(argv[2], sizeof(char), strlen(argv[2]), fp);*/
	ret = fwrite(buf, sizeof(char), strlen(buf), fp);
	printf("ret = %d\n", ret);

/*
 *    ret = fread(buf, 128, 1, fp);
 *    printf("buf = %s\n", buf);
 *    printf("ret = %d\n", ret);
 *    printf("==============\n");
 *    getchar();
 *    //循环读取
 *    while(fread(buf, sizeof(char), sizeof(buf) - 1, fp) > 0)
 *    {
 *        printf("%s", buf);
 *        memset(buf, 0, sizeof(buf));//清空buf
 *        usleep(100000);
 *        fflush(NULL);
 *        //字符串必须以尾零结束
 *    }
 *    memset(buf, 0, sizeof(buf));
 *
 *    ret = fread(buf, sizeof(char), sizeof(buf) - 1, fp);
 *    if (ret <= 0)
 *    {
 *        printf("fread failed!\n");
 *        [>perror("fread");<]
 *        return -1;
 *    }
 *    printf("buf = %s\n", buf);
 *    printf("ret = %d\n", ret);
 */
	return 0;
}
