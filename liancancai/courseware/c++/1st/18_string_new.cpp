#include <iostream>

using namespace std;

int main(void)
{
	int **p = NULL;

	string *str1;
	string str2 = "hello";

	str1 = new string;

	*str1 = "test";

	//str1 = &str2;
	
	p = new int *;
	*p = new int;

	**p = 123;

	cout << "**p = " << **p << endl;
	cout << "str1 = " << *str1 << endl;
	cout << "str2 = " << str2 << endl;

	delete *p;
	delete p;
	delete str1;
	//delete str1;
	return 0;
}
