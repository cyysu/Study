#include <iostream>

using namespace std;


void change(const int & a)
{
	//a = 456;
	cout << "func a  = " << a << endl;
}

int main(void)
{
	int a = 123;

	change(a);

	a = 456;

	cout << "a = " << a << endl;
	return 0;
}
