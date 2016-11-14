#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//声明一个外部命令
extern e;

/*static void hello(void);*/

void test(void)
{
	static int count = 0;
	if (count == 5)
	{
		return;
	}
	printf("test! count = %d %p\n", count, &count);
	count++;
	test();
}
int main(void)
{
	test();	
	/*printf("e = %d\n", e);*/
	/*hello();*/
	func();
	return 0;
}
