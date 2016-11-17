#include <iostream>

using namespace std;

void test(int & a)
{
	a = 1;

}
int main(void)
{
	int a = 123;
	int b = 456;
	int c[5] = {1,2,3,4,5};
	int *p = &a;
	
	int & q = c;
	
	q = b;
	//test(a);

	cout << "a = " << a << endl;
	cout << "p = " << *p << endl;

	q = 1122;
	cout << "&q = " << &q << endl;
	cout << "&a = " << &a << endl;
	cout << "q = " << q << endl;
	cout << "a = " << a << endl;
	return 0;
}
