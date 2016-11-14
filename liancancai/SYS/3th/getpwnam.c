#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pwd.h>

//检验getpwnam, getpwuid
int main(int argc, char const *argv[])
{
	 // struct passwd *getpwnam(const char *name);
	 // struct passwd *getpwuid(uid_t uid);
 	//   struct passwd {
  //              char   *pw_name;       /* username */
  //              char   *pw_passwd;     /* user password */
  //              uid_t   pw_uid;        /* user ID */
  //              gid_t   pw_gid;        /* group ID */
  //              char   *pw_gecos;      /* user information */
  //              char   *pw_dir;        /* home directory */
  //              char   *pw_shell;      /* shell program */
  //          };
	struct passwd *user = NULL;
	int uid;

	printf("please input a uid:");
	scanf("%d", &uid);

	user = getpwnam(argv[1]);
	printf("getpwnam========================\n");
	printf("name = %s\n", user->pw_name);
	printf("passwd = %s\n", user->pw_passwd);
	printf("pw_uid = %d\n", user->pw_uid);
	printf("pw_gid = %d\n", user->pw_gid);
	printf("gecos = %s\n", user->pw_gecos);
	printf("dir = %s\n", user->pw_dir);
	printf("shell = %s\n", user->pw_shell);

	user = getpwuid(uid);
	printf("getpwuid========================\n");
	printf("name = %s\n", user->pw_name);
	printf("passwd = %s\n", user->pw_passwd);
	printf("pw_uid = %d\n", user->pw_uid);
	printf("pw_gid = %d\n", user->pw_gid);
	printf("gecos = %s\n", user->pw_gecos);
	printf("dir = %s\n", user->pw_dir);
	printf("shell = %s\n", user->pw_shell);

	// free(user);	
	return 0;
}