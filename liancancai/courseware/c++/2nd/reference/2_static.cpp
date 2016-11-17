#include <iostream>

using namespace std;

extern int e;


void hello(void)
{
	static int count = 5;

	if (count == 0)
	{
		return ;
	}
	cout << "hello" << endl;
	count--;
	hello();
}
int *test(void)
{
	static int a = 123;

	cout << "func &a : " << &a << endl;
	cout << "test" << endl;
	
	return &a;
}

void test1(void)
{
	static int b = 456;
}
int main(void)
{
	int *p = NULL;

	//访问外部变量
	printf("extern : e = %d\n", e);


	hello();

	p = test();
	test1();

	static int c = 789;
	printf("main : p : %p\n", p);
	cout << "*p = " << *p << endl;
	//cout << "a = " << a << endl;
	return 0;
}
