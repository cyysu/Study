
#include <stdio.h>

int main(void)
{

	int a , b , c ; 	

	__asm__ __volatile__ (


	"mov	r0 , #1   \n"
	"mov	r1 , #2   \n"
	"mov	r2 , #3   \n"

	//压栈
	//"push   {r0}      \n"
	//"push   {r1}      \n"
	//"push   {r2}      \n"
	//"push	{r0,r1,r2}  \n" //必须有顺序
	//"push	{r0-r12 , lr}	  \n"
	"stmfd sp! , {r0-r12 , lr}  \n"

	//*****************
	
	"mov	r0 , #11  \n"
	"mov	r1 , #22  \n"
	"mov	r2 , #33  \n"

	//*****************
	//出栈
	//"pop	{r2}      \n"
	//"pop	{r1}      \n"
	//"pop	{r0}      \n"
	//"pop	{r0-r12 , lr}   \n"
	"ldmfd sp! , {r0-r12 , lr} \n"


	"mov	%0 , r0  \n"
	"mov	%1 , r1  \n"
	"mov	%2 , r2  \n"
	
	:"=r"(a),"=r"(b),"=r"(c)
	::"r0","r1","r2"
	);

	printf("a:%d b:%d c:%d \n" , a , b , c);

	return 0 ; 
}
