#include <iostream>

using namespace std;

char buf[1024];

int main(void)
{
	string *str = NULL;
	int i;

	str = new string[3];
	for (i = 0; i < 3; i ++)
	{
		cout << "please input a string: ";
		getline(cin, str[i]);
	}

	for (i = 0; i < 3 ; i++)
	{
		cout << str[i] << endl;
	}	

	return 0;
}
