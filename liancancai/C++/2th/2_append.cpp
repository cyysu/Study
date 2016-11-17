#include <iostream>

using namespace std;

int main(void)
{
	string str1 = "hello";
	string str2 = " world"; 
	string str3;

	str1.append(str2);

	cout << str1 << endl;

	str3.append(10, '#');	

	cout << str3 << endl;

	return 0;
}
