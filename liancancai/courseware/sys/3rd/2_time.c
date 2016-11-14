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

int main(int argc, char **argv)
{
	time_t t;
	time_t ret;

	//1 从1970年1月1日到此刻秒数，并存入t中
	ret = time(&t);
	if (ret == -1)
	{
		printf("time failed!\n");
		return -1;
	}

	printf("t = %d ret = %d\n", t, ret);

	struct tm *time = NULL;

	//转换时间秒数成格式
	/*t = 1;//1970年1月1日*/
	//表示本地时间
	time = localtime(&t);
	if (time == NULL)
	{
		printf("localtiime failed!\n");
		return -1;
	}

	printf("tm_sec = %d\n", time->tm_sec);
	printf("tm_min = %d\n", time->tm_min);
	printf("tm_hour = %d\n", time->tm_hour);
	printf("tm_mday = %d\n", time->tm_mday);
	printf("tm_mon = %d\n", time->tm_mon + 1);
	printf("tm_year = %d\n", time->tm_year + 1900);
	printf("tm_wday = %d\n", time->tm_wday);
	printf("==========\n");
	//表示国际标准时间 格林时间
/*
 *    time = gmtime(&t);
 *    if (time == NULL)
 *    {
 *        printf("localtiime failed!\n");
 *        return -1;
 *    }
 *
 *    printf("tm_sec = %d\n", time->tm_sec);
 *    printf("tm_min = %d\n", time->tm_min);
 *    printf("tm_hour = %d\n", time->tm_hour);
 *    printf("tm_mday = %d\n", time->tm_mday);
 *    printf("tm_mon = %d\n", time->tm_mon + 1);
 *    printf("tm_year = %d\n", time->tm_year + 1900);
 *    printf("tm_wday = %d\n", time->tm_wday);
 */

	
	printf("asctime = %s\n", asctime(time));
	printf("ctime = %s\n", ctime(&t));
	printf("mktime = %d\n", mktime(time));

	char buf[128] = {};
	//year-month-days hours:mintues:seconds
	/*strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", time);*/
	strftime(buf, sizeof(buf), "%D", time);//11/3/16

	printf("buf = %s\n", buf);

	return 0;
}
