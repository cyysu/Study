#include <iostream>

using namespace std;

int main(void)
{
	int a = 10;

	cout.setf(ios_base::oct, ios_base::basefield);
	cout << a << endl;

	cout.setf(ios_base::dec, ios_base::basefield);
	cout << a << endl;

	cout.setf(ios_base::hex, ios_base::basefield);
	cout.setf(ios_base::showbase);
	cout << a << endl;
	return 0;
}