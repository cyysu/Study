#include <iostream>

using namespace std;

int main(void)
{
	float f1 = 333.333;
	float f2 = 33;
	int i = 10;
	bool b1 = true;
	bool b2 = false;
	int a1 = 10;
	int a2 = -10;


	cout << "before ============" << endl; 
	cout << f1 << endl;
	cout << f2 << endl;
	cout << i << endl;

	cout << "after =============" << endl;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	// cout << fixed;
	cout.precision(1);
	cout << f1 << endl;
	cout << f2 << endl;
	cout << i << endl;

	cout << "before ============" << endl;
	cout << b1 << endl;
	cout << b2 << endl;

	cout << "after =============" << endl;
	cout.setf(ios_base::boolalpha);
	// cout.unsetf(ios_base::boolalpha);
	cout << b1 << endl;
	cout << b2 << endl;


	cout << "before ============" << endl;
	cout << i << endl;

	cout << "after =============" << endl;
	cout.setf(ios_base::showbase);
	// cout.setf(ios_base::uppercase);//显示16进制大写
	cout << hex << i << endl;

	// cout << "before ============" << endl;
	// cout << "a1 = " << a1 << endl;
	// cout << "a2 = " << a2 << endl;

	// cout << "after =============" << endl;
	// cout.setf(ios_base::showpos);
	// cout << "a1 = " << a1 << endl;
	// cout << "a2 = " << a2 << endl;
	return 0;
}
