#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


//调用exit 和 _exit 都会打印printf函数的内容
int main(void)
{
	printf("distinguish exit && _exit\n");

	// exit (0);
	_exit (0);

	while (1);

	return 0;
}
