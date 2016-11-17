#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(void)
{
	string str = "hello";
	string one("jim");
	char buf[128] = "test";

	//str.append("world");
	//str.append(buf);
	str.append(one);
	//str.append(10,'!');

	cout << str << endl;
	return 0;
}
