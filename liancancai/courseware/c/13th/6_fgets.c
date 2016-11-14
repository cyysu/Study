#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp = NULL;
	char buf[10];
	char *p = NULL;

	//打开一个可读文件
	fp = fopen(argv[1], "a");

	int ret;
	ret = fputs("hello\n", fp);
	if (ret == EOF)
	{
		printf("fputs failed!\n");
		return -1;
	}

/*
 *    while(fgets(buf, sizeof(buf), fp) != NULL)
 *    {
 *        printf("%s", buf);
 *        usleep(300000);
 *    }
 *    printf("==================\n");
 *
 *    printf("buf = %s\n", buf);
 *    p = fgets(buf, sizeof(buf), fp);
 *    if (p == NULL)
 *    {
 *        return -1;
 *    }
 *    printf("buf = %s : %p\n", buf, buf);
 *    printf("p = %s : %p\n", p, p);
 */
	return 0;
}
