#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int a = 10;

	printf("hello!\n");printf("world!\n");

	a = (10,20,30),40;

	printf("a = %d\n", a);
	a += 20;// => a = a + 20

	a*= 5 + 3;//153  => a = a * (5 + 3)

	/*b = 2 * 3 + 6;*/

	printf("a = %d\n",a);
	return 0;
}
