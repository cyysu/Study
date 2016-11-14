#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//利用gdb调试段错误

void segment(void)
{
	int *p = NULL;
	*p = 100;
}

int main(int argc, char *argv)
{
	segment();
	return 0;
}