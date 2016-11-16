#include <iostream>

using namespace std;

int main(void)
{
	int a;
	float f;
	char c;
	string str;
	char buf[128];

	// cout << "please input a int num: ";
	// cin >> a;
	// cout << "the num is :";
	// cout << a << endl;


	// cout << "pelase input a float num: ";
	// cin >> f;
	// cout << "the num is :";
	// cout << f << endl;

	// cout << "please input a char: ";
	// cin >> c;
	// cout << "the char is :";
	// cout << c << endl;

	cout << "please input a string :";
	getline(cin, str);
	cout << str << endl;

	cout << "please input a string :";
	cin.getline(buf, sizeof(buf));
	cout << buf << endl;

	return 0;
}