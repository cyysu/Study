#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//cp fread fwrite
int main(int argc, char **argv)
{
	FILE *fpr = NULL;
	FILE *fpw = NULL;
	char buf[1024] = {};
	int ret;


	fpr = fopen(argv[1], "r");

	fpw = fopen(argv[2], "w");

	while((ret = fread(buf, sizeof(char), sizeof(buf), fpr)) > 0)
	{
		fwrite(buf, sizeof(char), ret, fpw);
	}

	fclose(fpr);
	fclose(fpw);
	return 0;
}
