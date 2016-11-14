#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * test(void)
{
	int *a = NULL;

	a = (int *)malloc(4);

	*a = 1123;

	return a;
}

void test1(void)
{
	int b = 789;
}

void test2(int *p)
{
	p = (int *)malloc(4);
}
int main(void)
{
	int *p = NULL;

	/*p = test();*/
	test2(p);//想当于把p指向NULL传给函数，并不是把它本身地址传递过去
	*p = 456; 
	printf("*p = %d\n", *p);
	
/*
 *    p = test();
 *
 *    test1();
 *    printf("*p = %d\n", *p);
 *
 *    free(p);
 */
	return 0;
}
