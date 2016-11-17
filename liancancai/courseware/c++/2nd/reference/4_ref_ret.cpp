#include <iostream>

using namespace std;

int & test(int & b)
{
	static int a = 12;
	int *p = NULL;

	p = new int;
	if (p == NULL)
	{
		return b;
	}

	*p = 456;

	printf("func p = %p\n", p);
	return *p;

	return b;
}
int main(void)
{
	int ret;
	int a = 123;
	int & addr = test(a);

	cout << "addr = " << addr << "&addr = " << &addr << endl;
	delete &addr;
	//delete &addr;
	cout << "addr = " << addr << endl;

	ret = test(a);
	cout << "main : ret = " << &ret << endl;
	delete ret;
	
	
	cout << "ret = " << ret << endl;


	return 0;
}
