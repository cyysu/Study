#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <share.h>

//cp srcfilename destfilename
//srcfilename -> argv[1] -> fopen -> "r"
//destfilename -> argv[2] -> fopen -> "w"
int main(int argc, char **argv)
{
	FILE *fpr = NULL, *fpw = NULL;
	char ch;

	ERRP(argc != 3, "cmd format : cmd src dest!\n", goto ERR1);

    /*
	 *printf("src = %s\n", argv[1]);
	 *printf("dest = %s\n", argv[2]);
     */

	fpr = fopen(argv[1], "r");
	ERRP(NULL == fpr, "fopen read failed!\n", goto ERR1);

	fpw = fopen(argv[2], "w");
	ERRP(NULL == fpw, "fopen write failed!\n", goto ERR2);

	while((ch = fgetc(fpr)) != EOF)
	{
		/*printf("%c", ch);*/
		fputc(ch, fpw);

	}
	
	fclose(fpr);
	fclose(fpw);
	return 0;
ERR2:
	fclose(fpr);
ERR1:
	return -1;
}
