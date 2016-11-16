#include <iostream>

using namespace std;

int main(void)
{

	char s1[128];
	char s2[128] = "hello";
	string str1;// = "hello"; 
	string str2 = "this is a c++ program!";
	string *str3;

	str3 = &str2;

	//str1 += str2;

	cout << "sizeof() = " << sizeof(s1) << endl;
	cout << "sizeof() = " << sizeof(str1) << endl;
	cout << "str1.size() = " << str1.size() << endl;

	cout << "&s1 = " << &s1 << endl;
	cout << "&s2 = " << &s2 << endl;
	cout << "&str1 = " << &str1 << endl;
	cout << "&str2 = " << &str2 << endl;
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "sizeof(str1) = " << str1.size() << endl;
	cout << "sizeof(str2) = " << str2.size() << endl;

	return 0;
}
