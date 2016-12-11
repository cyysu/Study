
#ifndef _RES_H
#define _RES_H

typedef  volatile unsigned int   U32 ; 
typedef  volatile unsigned short U16 ; 
typedef  volatile unsigned char  U8  ; 

#define  NULL 0
typedef  unsigned int  size_t ; 
typedef  unsigned long ulong ; 


#define  GPM4CON   *(U32 *)0x110002E0
#define  GPM4DAT   *(U32 *)0x110002E4
#define  GPD0CON   *(U32 *)0x114000A0
#define  GPD0DAT   *(U32 *)0x114000A4
#define  GPX3CON   *(U32 *)0x11000C60
#define  GPX3DAT   *(U32 *)0x11000C64
#define  PRINT     *(U32 *)0xc3e11ad0



#endif //_RES_H
