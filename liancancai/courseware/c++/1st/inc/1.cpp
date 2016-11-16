#include <iostream>

using namespace std;

extern "C"
{
	void test(void);
}

int main(void)
{
	cout << "c++ : main stat!\n";
	test();
	cout << "c++ : main end!\n";
	return 0;
}
