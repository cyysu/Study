#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <shadow.h>

//测试getspnam
int main(int argc, char const *argv[])
{
	 // struct spwd *getspnam(const char *name);

  //      struct spwd *getspent(void);

  //      void setspent(void);

  //      void endspent(void);

  // struct spwd {
  //              char *sp_namp;     /* Login name */
  //              char *sp_pwdp;     /* Encrypted password */
  //              long  sp_lstchg;   /* Date of last change
  //                                    (measured in days since
  //                                    1970-01-01 00:00:00 +0000 (UTC)) */
  //              long  sp_min;      /* Min # of days between changes */
  //              long  sp_max;      /* Max # of days between changes */
  //              long  sp_warn;      # of days before password expires
  //                                    to warn user to change it 
  //              long  sp_inact;    /* # of days after password expires
  //                                    until account is disabled */
  //              long  sp_expire;   /* Date when account expires
  //                                    (measured in days since
  //                                    1970-01-01 00:00:00 +0000 (UTC)) */
  //              unsigned long sp_flag;  /* Reserved */
  //          };
	struct spwd *spw = NULL;

	spw = getspnam(argv[1]);

	printf("name = %s\n", spw->sp_namp);
	printf("pwdp = %s\n", spw->sp_pwdp);
	return 0;
}