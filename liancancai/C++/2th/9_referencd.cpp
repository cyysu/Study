#include <iostream>

using namespace std;

void show(double & a)
{
	cout << "show==========" << endl;
	cout << "value = " << a; 
	cout << "  addr = " << static_cast <void *> (&a) << endl;
}

int main(void)
{
	double a = 12.23;
	int b;
	long c;

	cout << "value = " << a;
	cout << "  addr =" << static_cast <void *> (&a) << endl;
	
	show(c);

	return 0;
}
