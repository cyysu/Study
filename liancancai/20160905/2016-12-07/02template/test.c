
#include "res.h"
#include "basedevice.h"

int (*printf)(const char *,...) = (void*) 0x43e11ad0 ; 


int number ;   //未初始化全局区 值随机

int _start(void)
{
	int a = 100 ; 
	int b = 20 ; 
	
	printf("%d %d \n" , a/b , a%b);

	printf("number:%d \n" , number);
#if 1
//  需要标准库的字符串操作
	int array[20]  = {11,12,13,14,15,16,17,18,19,20}; 

	int i ; 
	for(i = 0 ; i < 20 ; i++)
	{
		printf("array[%d]:%d \n" , i , array[i]);
	}


#endif

	return 0 ; 
}

