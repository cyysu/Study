

#include "res.h"
#include "basedevice.h"
#include "rtc.h"

static PRINT_T printf =  PRINTADDR ; 

int _start(void)
{
#if 0
	serial_init();
	serial_operation();
#endif

	serial_init_dev(0);
	serial_puts_dev("hello world \n" , 0);
	
	
	return 0 ; 
}


