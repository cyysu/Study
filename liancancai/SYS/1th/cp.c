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

//实现cp函数
int main(int argc, char ** argv)
{
	FILE *fpr = NULL;
	FILE *fpw = NULL;
	char buf[10];
	int ret = 1;

	fpr = fopen (argv[1], "r");
	ERRP (NULL == fpr, fopen fpr, goto ERR1);

	// fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
	
	fpw = fopen (argv[2], "w");
	ERRP (NULL == fpw, fopen fpw, goto ERR2);

	while (ret)
	{
		ret = fread (buf, 1, 1, fpr);
		 // size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
		fwrite (buf, 1, ret, fpw);
	}


	fclose (fpr);
	fclose (fpw);

	return 0;
ERR2:
	fclose(fpr);
ERR1:
	return 0;
}
