#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>


void test(int a, ...)
{
	va_list ap;
	va_start(ap, a);
	printf("test stat\n");

	printf("a = %d\n", a);	
	va_arg(ap, int);
	va_arg(ap, double);
    /*
	 *printf("char = %c\n", va_arg(ap, int));
	 *printf("float = %f\n", va_arg(ap, double));
     */
	printf("string = %s\n", va_arg(ap, char *));

	va_end(ap);

	printf("test end!\n");
}
int main(void)
{
	/*test(12);	*/
	/*test(1,2);	*/
	test(12, 'A', 3.456, "helljds", 123, 0);	
	return 0;
}
