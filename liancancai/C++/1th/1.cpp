#include <iostream>

using namespace std;

extern "C"
{
	void test(void);
}

int main(void)
{
	cout << "hello" << endl;

	test();

	return 0;
}
