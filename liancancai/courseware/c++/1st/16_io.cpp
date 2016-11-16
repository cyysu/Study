#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
	int a;
	char buf[10];
	string str;

	cout << "please input string : ";
	getline(cin, buf);
	////getline(cin, str);
	//cin.getline(buf, sizeof(buf));
	//cin >> str;
	//cin >> buf;

	cout << "str = " << str << endl;
	cout << "buf = " << buf << endl;

/*
 *    cout << "please input number : ";
 *    cin >> a;
 *
 *    cout << "a = " << a << endl;
 */

	
	
	return 0;
}
