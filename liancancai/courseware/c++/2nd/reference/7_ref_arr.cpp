#include <iostream>

using namespace std;

int main(void)
{
	int a[5] = {1,2,3,4,5};

	int & b = a[0];

	int i;

	for (i = 0; i < 5; i++)
	{
		cout << *(&b + i) << " ";
	}
	cout << endl;

	return 0;
}
