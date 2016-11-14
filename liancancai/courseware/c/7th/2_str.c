#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//求空间大小
//求字符串长度
//string : \0
int main(void)
{
	char s[] = "hel\0lo\0";

	s = "world";

	printf("sizeof(s) = %d\n", sizeof(s));//10 6
	printf("strlen(s) = %d\n", strlen(s));//5 5
	return 0;
}
