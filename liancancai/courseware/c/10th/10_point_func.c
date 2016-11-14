#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int e = 123;

//指针函数
void *hello(void)
{
	
	printf("hello!\n");
	
	return &e;
}
int main(void)
{
	printf("hello = %d\n", *(int *)hello());

	return 0;
}
