/*
 * S3C44B0 CPU specific code
 */

#include "res.h"
#include "rtc.h"

static PRINT_T printf =  PRINTADDR ; 

int rtc_get (struct rtc_time* tm)
{
	RTCCON |= 1;
	tm->tm_year  = bcd2bin(BCDYEAR);
	tm->tm_mon   = bcd2bin(BCDMON);
	tm->tm_wday   = bcd2bin(BCDDAYWEEK);
	tm->tm_mday   = bcd2bin(BCDDAY);
	tm->tm_hour  = bcd2bin(BCDHOUR);
	tm->tm_min  = bcd2bin(BCDMIN);
	tm->tm_sec  = bcd2bin(BCDSEC);

	if (tm->tm_sec==0) {
		/* we have to re-read the rtc data because of the "one second deviation" problem */
		/* see RTC datasheet for more info about it */
		tm->tm_year  = bcd2bin(BCDYEAR);
		tm->tm_mon   = bcd2bin(BCDMON);
		tm->tm_mday   = bcd2bin(BCDDAY);
		tm->tm_wday   = bcd2bin(BCDDAYWEEK);
		tm->tm_hour  = bcd2bin(BCDHOUR);
		tm->tm_min  = bcd2bin(BCDMIN);
		tm->tm_sec  = bcd2bin(BCDSEC);
	}

	RTCCON &= ~1;

	if(tm->tm_year >= 70)
		tm->tm_year += 1900;
	else
		tm->tm_year += 2000;

	return 0;
}

int rtc_set (struct rtc_time* tm)
{
	if(tm->tm_year < 2000)
		tm->tm_year -= 1900;
	else
		tm->tm_year -= 2000;

	RTCCON |= 1;
	BCDYEAR = bin2bcd(tm->tm_year);
	BCDMON = bin2bcd(tm->tm_mon);
	BCDDAY = bin2bcd(tm->tm_mday);
	BCDDAYWEEK= bin2bcd(tm->tm_wday);
	BCDHOUR = bin2bcd(tm->tm_hour);
	BCDMIN = bin2bcd(tm->tm_min);
	BCDSEC = bin2bcd(tm->tm_sec);
	RTCCON &= 1;

	return 0;
}

void rtc_reset (void)
{
	RTCCON |= 1;
	BCDYEAR = 0;
	BCDMON = 0;
	BCDDAY = 0;
	BCDDAYWEEK= 0;
	BCDHOUR = 0;
	BCDMIN = 0;
	BCDSEC = 0;
	RTCCON &= 1;
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

