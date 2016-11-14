#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char **argv)
{
	struct stat s;
	int i = 0;
	struct group *grp = NULL;


	stat(argv[1], &s);

	grp = getgrgid(s.st_gid);
	if (grp == NULL)
	{
		return -1;
	}

	printf("name : %s\n", grp->gr_name);
	printf("passwd : %s\n", grp->gr_passwd);
	printf("gid : %d\n", grp->gr_gid);
	while(grp->gr_mem[i] != NULL)
	{
		printf("member : %s ", grp->gr_mem[i]);
		i++;
	}
	printf("\n);
	return 0;
}
