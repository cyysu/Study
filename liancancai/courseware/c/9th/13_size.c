#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t my_strlen(const char *s)
{
	size_t i = 0;

	while(*s != '\0')
	{
		i++;
		s++;
	}
	return i;
}
int main(void)
{
	char s[] = "h     el\0lo";
	char *p = "hel\0lo";//p指向是一个常量区

	printf("my_strlen() = %d\n", my_strlen(s));
	printf("strlen() = %d\n", strlen(s));

	/*p = s;//表示p指向栈段，就有空间*/


	printf("strlen(s) = %d, sizeof(s) = %d\n", strlen(s), sizeof(s));
	//5 6 | 34 | 37
	printf("strlen(p) = %d, sizeof(p) = %d\n", strlen(p), sizeof(p));
	//5 4 | 34

	return 0;
}
