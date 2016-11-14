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
#include <dirent.h>
#include <glob.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>


int main(int argc, char **argv)
{
	int count = 0;
	printf("hello!\n");

	while(1)
	{
		if (count == 5)
		{
			/*kill(getpid(), 9);*/
			kill(getpid(), SIGKILL);
		}
		sleep(1);
		count++;
	}
	return 0;
}
