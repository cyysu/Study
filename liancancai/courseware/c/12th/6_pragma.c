#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//4
#pragma pack(2)
struct a_t{
	int a;
	char ch;
};

//表示恢复系统默认对齐方式
#pragma pack(0)

struct b_t{
	int a;
	char ch;
};

int main(void)
{
	printf("sizeof(struct a_t) = %d\n", sizeof(struct a_t));	
	printf("sizeof(struct b_t) = %d\n", sizeof(struct b_t));	
	return 0;
}
