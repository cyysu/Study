#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int a[10];
	/*char s[10] = {'h', 'e', 'l', 'l', 'o'};*/
	char s[] = "你好";

	printf("sizeof(s) = %d\n", sizeof(s));

    /*
	 *while(1)
	 *{
	 *    putchar("abcdefghijklmnopqrstuvwxyz"[rand() % 26]);
	 *    usleep(200000);
	 *    fflush(NULL);
	 *}
     */
	for (i = 0; i < 10; i++)
	{
		printf("s[%d] = %c\n", i, s[i]);
	}
	printf("s = %s\n", s);
	return 0;
}
