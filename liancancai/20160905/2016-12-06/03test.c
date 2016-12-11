
#include <stdio.h>

int main(void)
{
	int i = 0 ; 
	int b ; 

	b = i++ + i++ ; 
	//b = i++ + i++ ; 

	printf("b:%d  i:%d  \n" , b , i);

#if 0
	printf("%d  %d  \n" , i++ , i++);
	//					  0     1
	//					  1     2
	//					  2     1
	//					  1     0
	
	printf("%d  %d  \n" ,  i+=1 ,i);

	//printf("%d  %d  \n" , ++i , ++i);
	//					  3     4
	//					  4     3
	//					  2     3
#endif

	return 0 ; 
}
