
#include <stdio.h>


//位段
#define BUILD_BUG_ON_ZERO(e) (sizeof(struct { int:-!!(e); }))
//相同类型为1  不相同类型为0
#define __same_type(a, b) __builtin_types_compatible_p(typeof(a), typeof(b))
#define __must_be_array(a) BUILD_BUG_ON_ZERO(__same_type((a), &(a)[0]))
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]) + __must_be_array(arr))


#define  NR(x)   (sizeof(x)/sizeof(x[0]))   //XX

void function(int *array , int *p);

int main(void)
{
	int array[10] ; 

	int *p  ; 
	

	printf("%s size:%d \n" ,__func__, ARRAY_SIZE(array));  //10  //对
	printf("%s size:%d \n" ,__func__, ARRAY_SIZE(p));      //8

	function(array , p);

	return 0 ; 
}

void function(int array[1000000] ,int *p)
{
	printf("%s size:%d \n" ,__func__ ,  NR(array)); //2
	printf("%s size:%d \n" ,__func__ ,  NR(p));     //8
}
