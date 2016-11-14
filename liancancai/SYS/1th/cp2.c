#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INFORMATION   do{					\
		printf("file: %s\n", __FILE__);		\
		printf("func: %s\n", __func__);		\
		printf("line: %d\n", __LINE__);		\
}while(0)

#define ERRP(condition, string, ret) do{	\
		if(condition)						\
		{									\
			printf(#string" failed\n");		\
			INFORMATION;					\
			ret;							\
		}									\
}while(0)

int main(int argc, char **argv)
{
	FILE *fpw = NULL, *fpr = NULL;
	int ret = 1;
	char buf[128];

	fpr = fopen(argv[1], "r");
	ERRP(NULL == fpr, fopen fpr, goto ERR1);

	fpw = fopen(argv[2], "w");
	ERRP(NULL == fpw, fopen fpw, goto ERR2);

	while(ret > 0)
	{
		ret = fread(buf, sizeof(char), sizeof(buf), fpr);

		fwrite(buf, sizeof(char), ret, fpw);
	}


	fclose(fpr);
	fclose(fpw);
	return 0;

ERR2:
	fclose(fpr);	
ERR1:
	return -1;
}
