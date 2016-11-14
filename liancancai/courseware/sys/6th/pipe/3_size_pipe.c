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
	int fd[2];
	char buf[1024];
	int count = 0;


	pipe(fd);

	/*printf("SSIZE_MAX = %d\n", SSIZE_MAX);*/
	printf("BUF_SIZ = %d\n", BUF_SIZE);

	if (fork() == 0)
	{
		//write
		/*sleep(1);*/
		close(fd[0]);
		while(1)
		{
			write(fd[1], buf, sizeof(buf));
			//64K
			printf("count = %d\n", count++);
		}
	}

	wait(NULL);
	close(fd[0]);
	close(fd[1]);
	//read()
	return 0;
}
