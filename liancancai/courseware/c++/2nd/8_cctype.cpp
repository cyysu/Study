#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
	char ch;

	cout << "please input char : ";
	cin.get(ch).get();

	//cout << "ch = " << ch << endl;

	if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
	{
		printf("c : yes\n");
	}
	else
	{
		printf("c : no\n");
	}

	if (isalpha(ch))
	{
		cout << "c++ : yes" << endl;
	}
	else
	{
		cout << "c++ : no" << endl;
	}
	return 0;
}
