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
#include <crypt.h>
#include <time.h>
#include <dirent.h>
#include <glob.h>
#include <signal.h>
#include <sys/wait.h>

#define INFORMATION   do{					\
		printf("file: %s\n", __FILE__);		\
		printf("func: %s\n", __func__);		\
		printf("line: %d\n", __LINE__);		\
}while(0)

#define ERRP(condition, string, ret) do{	\
		if(condition)						\
		{									\
			printf(#string" failed\n");		\
			INFORMATION;					\
			ret;							\
		}									\
}while(0)

int main(int argc, char **argv)
{
	int ret;

	ret = fork();

	if (0 != ret)
	{
		int status;
		wait(&status);
		     //   WIFEXITED(status)
       //        returns  true  if  the child terminated normally, that is, by calling exit(3) or _exit(2), or by
       //        returning from main().

       // WEXITSTATUS(status)
       //        returns the exit status of the child.  This consists of the least significant 8 bits of the sta‐
       //        tus  argument that the child specified in a call to exit(3) or _exit(2) or as the argument for a
       //        return statement in main().  This macro should be employed only if WIFEXITED returned true.

       // WIFSIGNALED(status)
       //        returns true if the child process was terminated by a signal.

       // WTERMSIG(status)
       //        returns the number of the signal that caused the child process to terminate.  This macro  should
       //        be employed only if WIFSIGNALED returned true.
		printf("parenst \n");

		printf("WIFEXITED(status) = %d\n" , WIFEXITED(status));
		if (WIFEXITED(status))
		{
			printf("WEXISTATUS = %d\n", WEXITSTATUS(status));
		}

		printf("WIFSIGNALED(status) = %d\n", WIFSIGNALED(status));
		if(WIFSIGNALED(status))
		{
			printf("WTERMSIG = %d\n", WTERMSIG(status));
		}
	}
	else
	{
		printf("child | pid = %d\n", getpid());
		// exit(123);
		abort();
		// kill(getpid(), 9);
		printf("child \n");
	}
	return 0;
}
