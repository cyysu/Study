#include <iostream>

using namespace std;

int main(void)
{
	int a = 123;
	const int & b = a;

	//a = 456;

	b = 789;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	return 0;
}
