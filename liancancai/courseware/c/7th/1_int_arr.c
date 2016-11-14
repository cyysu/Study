#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int a[5];
	char s[10] = {};
	// => hello
	// =?> %s hello
	for (i = 0; i < 5; i++)
	{
		printf("please input %d nunber : ", i + 1);
		scanf("%c", &s[i]);
		while (getchar() != '\n')
			;
	}
	
	printf("s = %s\n", s);
    /*
	 *for (i = 0; i < 5; i++)
	 *{
	 *    printf("%d ", a[i]);
	 *}
	 *printf("\n");
     */

	return 0;
}
