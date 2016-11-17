#include <iostream>

using namespace std;


void swap(int & a, int & b)
{
	int temp;

	cout << "int" << endl;
	temp = a;
	a = b;
	b = temp;
}
void swap(double & a, double & b)
{
	double temp;

	cout << "double" << endl;
	temp = a;
	a = b;
	b = temp;
}
int main(void)
{
	int a = 1, b = 2;
	double d1 = 3.44, d2 = 4.55;
	
	cout << "a = " << a << " b = " << b << endl;
	swap(a, b);
	cout << "a = " << a << " b = " << b << endl;
	cout << "d1 = " << d1 << " d2 = " << d2 << endl;
	swap(d1, d2);
	cout << "d1 = " << d1 << " d2 = " << d2 << endl;
	return 0;
}
