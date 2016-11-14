#define _GNU_SOURCE
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
#include <time.h>
#include <sys/utsname.h>


int main(int argc, char **argv)
{
	char name[128];

	printf("getlogin = %s\n", getlogin());

	gethostname(name, sizeof(name));
	printf("name = %s\n", name);
	strcpy(name,"www.baidu.com"); 
	sethostname(name, strlen(name));

	printf("name = %s\n", name);

	struct utsname info;
	uname(&info);

	printf("sysname = %s\n", info.sysname);
	printf("nodename = %s\n", info.nodename);
	printf("release = %s\n", info.release);
	printf("version = %s\n", info.version);
	printf("machine = %s\n", info.machine);
#ifdef _GNU_SOURCE
	printf("domainname = %s\n", info.domainname);
#endif
	return 0;
}
