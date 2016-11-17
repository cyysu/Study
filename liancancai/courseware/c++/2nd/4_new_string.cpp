#include <iostream>

using namespace std;

char buf[1024];

int main(void)
{
	int i;
	string *p = NULL;

	p = new (buf) string [5];
	if (p == NULL)
	{
		printf("new failed!\n");
		return -1;
	}
	for (i = 0; i < 5; i++)
	{
		cout << "please input " << i + 1 << " name : ";
		getline(cin, p[i]);
	}

	for (i = 0; i < 5; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	return 0;
}
