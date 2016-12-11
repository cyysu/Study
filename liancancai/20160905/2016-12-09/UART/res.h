
#ifndef _RES_H
#define _RES_H

#define BUILD_BUG_ON_ZERO(e) (sizeof(struct { int:-!!(e); }))
#define __same_type(a, b) __builtin_types_compatible_p(typeof(a), typeof(b))
#define __must_be_array(a) BUILD_BUG_ON_ZERO(__same_type((a), &(a)[0]))
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]) + __must_be_array(arr))

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
#define  GPA0CON   *(U32 *)0x11400000
#define  GPA0DAT   *(U32 *)0x11400004
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

//UART  register

// 0x1380_0000, 0x1381_0000, 0x1382_0000, 0x1383_0000, 0x1384_0000

#define  uartbase  0x13800000
#define  ULCONn    *(U32 *)(uartbase + 0x0000 )
#define  UCONn     *(U32 *)(uartbase + 0x0004 )
#define  UFCONn    *(U32 *)(uartbase + 0x0008 )
#define  UMCONn    *(U32 *)(uartbase + 0x000C )
#define  UTRSTATn  *(U32 *)(uartbase + 0x0010 )
#define  UERSTATn  *(U32 *)(uartbase + 0x0014 )
#define  UFSTATn   *(U32 *)(uartbase + 0x0018 )
#define  UMSTATn   *(U32 *)(uartbase + 0x001C )
#define  UTXHn     *(U32 *)(uartbase + 0x0020 )
#define  URXHn     *(U32 *)(uartbase + 0x0024 )
#define  UBRDIVn   *(U32 *)(uartbase + 0x0028 )
#define  UFRACVALn *(U32 *)(uartbase + 0x002C )
#define  UINTPn    *(U32 *)(uartbase + 0x0030 )






#endif //_RES_H
