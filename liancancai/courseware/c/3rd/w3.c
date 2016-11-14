#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//char 
// a	ch >= 'a' && ch <= 'z' 97
// A	ch >= 'A' && ch <= 'Z' 65
int main(void)
{
	char ch;

	printf("please input char: ");
	scanf("%c", &ch);

	printf("old ch = %c\n", ch);
	ch = (ch >= 'a' && ch <= 'z' || ch >= 'A' &&ch <= 'Z') ? ((ch >= 'a') ? (ch - 32) : (ch + 32)) : (ch);
	printf("new ch = %c\n", ch);
	return 0;
}
