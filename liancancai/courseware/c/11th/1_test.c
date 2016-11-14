#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef void (FUNC)(void);

//1
void hello(void)
{
	printf("hello!\n");
}
//2
void world(void)
{
	printf("world!\n");
}

//

/*void test(void (*func)(void))*/
void test(FUNC *func)
{
	func();
}

int main(void)
{
	test(world);

	return 0;
}
