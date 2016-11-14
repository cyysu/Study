#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

//测试time
int main(int argc, char **argv)
{
	   // tim_t tim(tim_t *t);
	time_t t;
	int ret;
	struct tm *tim = NULL;

	char buf[128] = {};

	ret = time(&t);
	ERRP(-1 == ret, time, goto ERR1);

	printf("%ld\n", t);

	// struct tm *localtim(const tim_t *timp);
	//            struct tm {
 //               int tm_sec;         /* seconds */
 //               int tm_min;         /* minutes */
 //               int tm_hour;        /* hours */
 //               int tm_mday;        /* day of the month */
 //               int tm_mon;         /* month */
 //               int tm_year;        /* year */
 //               int tm_wday;        /* day of the week */
 //               int tm_yday;        /* day in the year */
 //               int tm_isdst;       /* daylight saving tim */
 //           };

	 // char *asctime(const struct tm *tm);
  //      char *asctime_r(const struct tm *tm, char *buf);

  //      char *ctime(const time_t *timep);
  //      char *ctime_r(const time_t *timep, char *buf);

  //      struct tm *gmtime(const time_t *timep);
  //      struct tm *gmtime_r(const time_t *timep, struct tm *result);

  //      struct tm *localtime(const time_t *timep);
  //      struct tm *localtime_r(const time_t *timep, struct tm *result);

  //      time_t mktime(struct tm *tm);

	printf("localtime=========================\n");
	tim = localtime(&t);
	printf("%d-%d-%d %d:%d:%d\n", tim->tm_year + 1900, 
								  tim->tm_mon,
								  tim->tm_mday,
								  tim->tm_hour,
								  tim->tm_min,
								  tim->tm_sec);

	printf("gmtime============================\n");
	tim = gmtime(&t);
	printf("%d-%d-%d %d:%d:%d\n", tim->tm_year + 1900, 
								  tim->tm_mon,
								  tim->tm_mday,
								  tim->tm_hour,
								  tim->tm_min,
								  tim->tm_sec);

	printf("asctime==========================\n");
	printf("%s", asctime(tim));

	printf("ctime============================\n");
	printf("%s", ctime(&t));

	printf("mktime===========================\n");
	printf("%ld\n", mktime(tim));

	 // size_t strftime(char *s, size_t max, const char *format,
  //                      const struct tm *tm);

	ret = strftime(buf, sizeof(buf), "%Y %m", tim);
	printf("strftime=========================\n");
	printf("%s\n", buf);

	return 0;
ERR1:
	return -1;
}
