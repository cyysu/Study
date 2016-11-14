#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//8
struct a_t{
	/*int a;//4*/
	char ch;//1
	double d;//8
    /*
	 *char ch1;
	 *char ch2;
     */
	/*short s;*/
	/*int b;*/
};

int main(void)
{
	struct a_t a;

    /*
	 *printf("a.a = %p\n", &a.a);
	 *printf("a.ch = %p\n", &a.ch);
	 *printf("a.s = %p\n", &a.s);
	 *printf("a.ch1 = %p\n", &a.ch1);
     */
	printf("sizeof(struct a_t) = %d\n", sizeof(struct a_t));

	return 0;
}
