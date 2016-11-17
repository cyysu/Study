#include <iostream>

using namespace std;

void show(int a)
{
	cout << a << endl;
}

void show(int a, int b)
{
	cout << a << endl;
	cout << b << endl;
}

void show(double a)
{
	cout << a << endl;
}

int main(void)
{
	int a = 1, b = 2;
	double c = 3.33;	

	show(a);
	show(a, b);
	show(c);

	return 0;
}
