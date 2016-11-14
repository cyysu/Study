#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <shadow.h>
#define _GNU_SOURCE    
#include <crypt.h>

int main(int argc, char **argv)
{

	// char *crypt(const char *key, const char *salt);
	char *p = NULL;

	p = crypt(argv[1], "$6$GbHJJMwg$");

	printf("%s\n", p);
	return 0;
}
