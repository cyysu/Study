#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void)
{
	int a = 10;
	float f = 3.3333333;
	int i;
	// cout << "#";
	// cout << setw(10) << a;
	// cout << "#" << endl;
	// cout << setprecision(4) << f << endl;
	cout << "original num";
	cout << setw(13) << "sqrt num" << endl;

	for (i = 10; i <= 100; i += 10)
	{
		cout << setw(5) << i;
		cout << setw(20) << sqrt(i) << endl;
	}

	return 0;
}