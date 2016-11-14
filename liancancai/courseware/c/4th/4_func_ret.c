#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//flag => 1 -> +
//flag => 2 -> *
int add_mul(int a,int b, int flag)
{
	if (flag == 1)
	{
		return a + b;
	}
	else
	{
		return a * b;
	}
}
int mul(int a, int b)
{
	return add(a, b);
}
int add(int a, int b)//形参
{
	/*a = 12;*/

	printf("add a = %d %p b = %d %p\n", a, &a, b, &b);

	return a + b;
/*
 *    int a = 3, b = 2;
 *    int c;
 *
 *    c = a + b;
 */

    /*
	 *return 2147483647 + 1;
	 *return 256;
	 *return c;
     */
	
}

void test(char ch, int a, float f)
{
	printf("test!\n");
	printf("ch = %c\n", ch);
	printf("a = %d\n", a);
	printf("f = %f\n", f);
}
// 0 ~ 255
int main(void)
{
	int a, b;

	printf("mul = %d\n",mul(2, 3));

	/*test(12345, 'A', "hlkdsk", 3.456);*/

	a = add(2, 3) + 123;

	printf("please input a and b : ");
	scanf("%d%d", &a, &b);// 2 3

	printf("add = %d\n", add(a,b));//实参
	printf("mul = %d\n", mul(a, b));
	printf("add = %d\n", add_mul(a, b, 1));
	printf("mul = %d\n", add_mul(a, add(b + 2, 2), 2));

	printf("main : a = %d %p, b = %d %p\n", a, &a, b, &b);


	/*printf("add = %ld\n", add());*/
	return 0;
}
