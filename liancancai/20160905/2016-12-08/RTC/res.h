
#ifndef _RES_H
#define _RES_H

typedef  int (*PRINT_T)(const char *,...) ; 
#define  PRINTADDR     (void*)0x43e11ad0 

typedef  volatile unsigned int   U32 ; 
typedef  volatile unsigned short U16 ; 
typedef  volatile unsigned char  U8  ; 

#define  NULL 0
typedef  unsigned int  size_t ; 
typedef  unsigned long ulong ; 
typedef  unsigned int u32 ; 
typedef  unsigned short u16 ; 
typedef  unsigned char  u8 ; 



#define  GPM4CON   *(U32 *)0x110002E0
#define  GPM4DAT   *(U32 *)0x110002E4
#define  GPD0CON   *(U32 *)0x114000A0
#define  GPD0DAT   *(U32 *)0x114000A4
#define  GPX3CON   *(U32 *)0x11000C60
#define  GPX3DAT   *(U32 *)0x11000C64
#define  PRINT     *(U32 *)0xc3e11ad0

//rtc register
#define  rtcbase    0x10070000
#define  INTP       *(U32 *)(rtcbase + 0x0030 )
#define  RTCCON     *(U32 *)(rtcbase + 0x0040 ) 
#define  TICCNT     *(U32 *)(rtcbase + 0x0044 ) 
#define  RTCALM     *(U32 *)(rtcbase + 0x0050 ) 
#define  ALMSEC     *(U32 *)(rtcbase + 0x0054 ) 
#define  ALMMIN     *(U32 *)(rtcbase + 0x0058 ) 
#define  ALMHOUR    *(U32 *)(rtcbase + 0x005C ) 
#define  ALMDAY     *(U32 *)(rtcbase + 0x0060 ) 
#define  ALMMON     *(U32 *)(rtcbase + 0x0064 ) 
#define  ALMYEAR    *(U32 *)(rtcbase + 0x0068 ) 
#define  BCDSEC     *(U32 *)(rtcbase + 0x0070 ) 
#define  BCDMIN     *(U32 *)(rtcbase + 0x0074 ) 
#define  BCDHOUR    *(U32 *)(rtcbase + 0x0078 ) 
#define  BCDDAYWEEK *(U32 *)(rtcbase + 0x0080 ) 
#define  BCDDAY     *(U32 *)(rtcbase + 0x007C ) 
#define  BCDMON     *(U32 *)(rtcbase + 0x0084 ) 
#define  BCDYEAR    *(U32 *)(rtcbase + 0x0088 ) 
#define  CURTICCNT  *(U32 *)(rtcbase + 0x0090 ) 







#endif //_RES_H
