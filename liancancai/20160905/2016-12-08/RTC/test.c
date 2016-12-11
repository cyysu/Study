

#inclde "res.h"
#include "basedevice.h"
#include "rtc.h"

static PRINT_T printf =  PRINTADDR ; 
#define    BCDDATE(X)	(((X)&0xF)+(((X)>>4)&0xF)*10)
#define    DATEBCD(X)	(((X)%10) | (((X)/10)<<4))

void read_RTC_date(void);
void set_RTC_date(void);

int _start(void)
{

#if 1
	struct rtc_time time ; 
	rtc_get(&time);
	printf("sec:%d min:%d hour:%d day:%d mon:%d year:%d \n" , time.tm_sec , time.tm_min , time.tm_hour , time.tm_mday , time.tm_mon , time.tm_year);
#else


//	read_RTC_date();
//	set_RTC_date();

#endif

	return 0 ; 
}


void read_RTC_date(void)
{
	printf("sec:%d \n" , BCDDATE(BCDSEC));
	printf("min:%d \n" , BCDDATE(BCDMIN));
	printf("hour:%d \n" ,BCDDATE(BCDHOUR));
	printf("dayweek:%d \n" ,BCDDATE(BCDDAYWEEK));
	printf("day:%d \n" ,BCDDATE(BCDDAY));
	printf("mon:%d \n" ,BCDDATE(BCDMON));
	printf("year:%d \n" ,BCDDATE(BCDYEAR)+2000);
}

void set_RTC_date(void)
{
	int year = 2016 ; 
	int mon = 12 ; 
	int day = 11 ; 
	int dayweek = 7 ; 
	int hour = 23 ; 
	int min = 59 ; 
	int sec = 40 ; 

	RTCCON |= 0x1 ;   //写1

	BCDSEC = DATEBCD(sec);
	BCDMIN= DATEBCD(min);
	BCDHOUR= DATEBCD(hour);
	BCDDAY= DATEBCD(day);
	BCDDAYWEEK= DATEBCD(dayweek);
	BCDMON= DATEBCD(mon);
	BCDYEAR= DATEBCD(year-2000);
	
	RTCCON &= ~0x1 ;   //写1
}
