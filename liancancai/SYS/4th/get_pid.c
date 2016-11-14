#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	printf("pid = %d, ppid= %d\n", getpid(), getppid());
	
	getchar();
	return 0;
}