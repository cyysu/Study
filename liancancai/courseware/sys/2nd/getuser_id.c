#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pwd.h>

int main(int argc, char **argv)
{
	printf("uid = %d\n", getuid());
	printf("euid = %d\n", geteuid());

	return 0;
}
