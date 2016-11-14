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
	glob_t g;
	int i;
	// int glob(const char *pattern, int flags,
 //                int (*errfunc) (const char *epath, int eerrno),
 //                glob_t *pglob);
	ret = glob(argv[1], GLOB_NOSORT, NULL, &g);
	if(ret == GLOB_NOMATCH)
	{
		printf("not found\n");
		return 0;
	}
	// ERRP(ret != 0, glob, goto ERR1);
	 // typedef struct {
  //              size_t   gl_pathc;    /* Count of paths matched so far  */
  //              char   **gl_pathv;    /* List of matched pathnames.  */
  //              size_t   gl_offs;     /* Slots to reserve in gl_pathv.  */
  //          } glob_t;
	i  = 0;
	while(g.gl_pathv[i] != NULL)
	{
		printf("g.gl_pathv = %s\n", g.gl_pathv[i]);
		i++;
	}

	return 0;

}
