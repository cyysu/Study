#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp = NULL;
	char ch;

	fp = fopen(argv[1], argv[2]);

	//hello 
	/*fseek(fp, 2, SEEK_SET);*/
	fseek(fp, -2, SEEK_END);
	printf("ftell = %d\n", ftell(fp));//
	fseek(fp, 1, SEEK_CUR);
	printf("ftell = %d\n", ftell(fp));//
	fseek(fp, 0, SEEK_SET);
	printf("ftell = %d\n", ftell(fp));// 0

	/*ch = fgetc(fp);*/

	while((ch = fgetc(fp)) != EOF)
	{
		printf("%c", ch);
		usleep(300000);
		fflush(NULL);
	}
	printf("=============\n");
	/*fseek(fp, 0, SEEK_SET);*/
	rewind(fp);

	while((ch = fgetc(fp)) != EOF)
	{
		printf("%c", ch);
		usleep(300000);
		fflush(NULL);
	}
	/*printf("ch = %c\n", ch);*/
	return 0;
}
