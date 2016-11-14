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
	struct stat s;
	struct passwd *pwd = NULL;

	stat(argv[1], &s);
	
	s.st_uid = 0;//表示用户uid
	
	pwd = getpwuid(s.st_uid);
	if (pwd == NULL)
	{
		printf("getpwuid failed!\n");
		return -1;
	}

	printf("%s:%s:%d:%d:%s:%s:%s\n", pwd->pw_name, pwd->pw_passwd, pwd->pw_uid, pwd->pw_gid, pwd->pw_gecos, pwd->pw_dir, pwd->pw_shell);

	while((pwd = getpwent()) != NULL)
	{
		printf("name : %10s | shell: %s\n", pwd->pw_name, pwd->pw_shell);
	}
	setpwent();
	printf("=========\n");
	while((pwd = getpwent()) != NULL)
	{
		printf("name : %10s | shell: %s\n", pwd->pw_name, pwd->pw_shell);
	}
	endpwent();
	return 0;
}
