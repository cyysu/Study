#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <grp.h>

int main(int argc, char const *argv[])
{
	// struct group *getgrnam(const char *name);
	// struct group *getgrgid(gid_t gid);

	  // struct group {
   //             char   *gr_name;       /* group name */
   //             char   *gr_passwd;      group password 
   //             gid_t   gr_gid;        /* group ID */
   //             char  **gr_mem;        /* group members */
   //         };

	struct group *grp = NULL;
	int gid;
	int i = 0;
	grp = getgrnam(argv[1]);

	printf("getgrnam=====================\n");
	printf("name = %s\n", grp->gr_name);
	printf("passwd = %s\n", grp->gr_passwd);
	printf("gid = %d\n", grp->gr_gid);
	while(grp->gr_mem[i] != NULL)
	{
		printf("members = %s\n", grp->gr_mem[i]);
		i ++;
	}

	printf("please input a gid:");
	scanf("%d", &gid);

	printf("getgrgid=====================\n");
	grp = getgrgid(gid);
	printf("name = %s\n", grp->gr_name);
	printf("passwd = %s\n", grp->gr_passwd);
	printf("gid = %d\n", grp->gr_gid);
	i = 0;
	while(grp->gr_mem[i] != NULL)
	{
		printf("members = %s\n", grp->gr_mem[i]);
		i ++;
	}
	return 0;
}