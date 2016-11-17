#include <iostream>

using namespace std;

void prt(int a = 1, int b = 2)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;	
}


int main(void)
{
	int a = 3, b = 4;	

	prt();

	prt(a);
	prt(a, b);

	return 0;
}
