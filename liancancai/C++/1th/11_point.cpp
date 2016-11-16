#include <iostream>

using namespace std;

int main(void)
{
	string *str;
	char *buf;

	str = new string;
	*str = "hello";
	cout << *str << endl;
	cout << "str size: " << str->size() << endl; 

	buf = new char [128];

	cout << "please input a string:" ;
	cin.getline(buf, 128);


	cout <<  buf << endl;

	delete str;
	delete [] buf;

	return 0;
}