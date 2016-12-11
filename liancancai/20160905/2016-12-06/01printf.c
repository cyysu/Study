
int main(void)
{
	
	__asm__ __volatile__ (

	".data		\n"    //数据段
	"Str:		\n"    //字符串标记
	".string	\"hello world \\n\" \n"   //字符串
	".align	2	\n"	   //字符串的对齐方式
	
	".text		\n"
	"stmfd sp! , {r0-r12 , lr}   \n"

	//printf
	"ldr	r0 , =Str	\n"
	"mov	lr , pc     \n"
	"b	printf			\n"


	"ldmfd sp! , {r0-r12 , lr}   \n"
	"mov	pc , lr				 \n"
	);


	return 0 ;
}
