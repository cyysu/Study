
#include <stdio.h>
#include <stdlib.h>

//位段
struct student
{
	char	 a:1 ;
	char	 b:2 ; 
	char	 c:5 ; 
};

int main(void)
{
	//  !!   不会改变真假关系 ,但是数值上只能出现0或者1
	//int array[-3] ; 

	printf("size:%d \n" , sizeof(struct student));
	//结构体的类型定义
	printf("size:%d \n" , sizeof(struct {int a;int b;}));
	//结构体的位段类型定义
	printf("size:%d \n" , sizeof(struct {int:0;}));
	printf("%d \n" , 	__builtin_types_compatible_p(int , char));


	return 0 ; 
}


