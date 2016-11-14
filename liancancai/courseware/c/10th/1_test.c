#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a[5] = {1,2,3,4,5};
	int *p = NULL;

	/*p = a;*/
	a = p;
	return 0;
}
