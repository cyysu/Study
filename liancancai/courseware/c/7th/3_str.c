#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strlen(char s[]);

void display(char s[])
{
	printf("func : sizeof(s) = %d\n", sizeof(s));
	printf("func : strlen(s) = %d\n", strlen(s));
	printf("func : my_strlen(s) = %d\n", my_strlen(s));
}

int my_strlen(char s[])
{
	int i = 0;
	while(s[i] != '\0')
		i++;
	return i;
}
int main(void)
{
	char s[128] = "hello world\0jjjj";
	char s1[128] = "kkkkkkkkkkkkkkkkkkkkkkkkk";

    /*
	 *printf("s = %s\n", s1);
	 *bzero(s1, sizeof(s1));
	 *printf("s = %s\n", s1);
     */

	printf("s = %s\n", s1);
	/*strcpy(s1 + 3, s + 4);*/
	strncpy(s1, s+10, 5);
	printf("s = %s\n", s1);
	printf("s1 + 13 = %c\n", s1[13]);

	/*s1 = s;*/


	printf("main : sizeof(s) = %d\n", sizeof(s));
	printf("main : strlen(s) = %d\n", strlen(s));
	printf("main : my_strlen(s) = %d\n", my_strlen(s));
	display(s);
	return 0;
}
