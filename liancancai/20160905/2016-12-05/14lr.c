
#include <stdio.h>

__asm__ (
".global T_Sub   \n"
"T_Sub:   		 \n"


"bx	lr			 \n"
);

__asm__ (
".global T_Add   \n"  //全局函数
"T_Add:          \n"  //T_Add函数

"stmfd sp! , {lr} \n"

"bl	T_Sub		 \n"

"add	r0 , r0 , r1    \n"
//"mov	pc , lr  \n"  //回复现场
"ldmfd sp! , {lr}\n"
"bx	lr			 \n"  //是mov pc , lr 的简写
);

int main(void)
{

	int sum = 0 ; 
	
	__asm__ __volatile__ (
	//保护main的现场
	"stmfd sp! , { lr}  \n"

	"mov	r0 , #22  \n"
	"mov	r1 , #33  \n"

	"bl	T_Add		  \n"

#if 0
	//跳过去之前先要保护现场
	"mov	lr , pc   \n"
//	"nop	          \n"  //两句之间不可以有任何指令  //空指令  mov r0 , r0
	"b	T_Add         \n"
#endif


	"mov	%0 , r0   \n"

	"ldmfd sp! , { lr}  \n"

	:"=r"(sum)
	::"r0","r1"
	);

	printf("sum:%d \n" , sum);

	return 0 ; 
}
