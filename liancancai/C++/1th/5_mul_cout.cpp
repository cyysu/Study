#include <iostream>

using namespace std;

int main(void)
{
	int num = 16;
	float f = 33333333.3333333;

	cout << "dec: " << dec << num << endl;
	cout << "oct: " << oct << num << endl;
	cout << "hex: " << hex << num << endl;

	cout << "#";
	cout.width(15);
	cout.fill('-');
	cout << left << f;
	cout << "#" << endl;
	return 0;
}