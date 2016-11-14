#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp = NULL;
	int a = 123, b;
	char buf[128] = "hello", tmp[128] = {};
	int ret;


    /*
	 *fp = fopen(argv[1], "w");
	 *ret = fprintf(fp, "%d : %s", a, buf);
     */
	fp = fopen(argv[1], "r");

	ret = fscanf(fp, "%d : %s", &b, tmp);

	printf("ret = %d\n", ret);
	printf("b = %d tmp = %s\n", b, tmp);

	fclose(fp);
	return 0;
}
