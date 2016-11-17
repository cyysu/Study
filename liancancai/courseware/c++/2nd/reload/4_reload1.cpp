#include <iostream>

using namespace std;

void test(int a)
{
	cout << "a" << endl;
}
void test(int & a)
{
	cout << "& a" << endl;
}
void test(int *a)
{
	cout << "* a" << endl;
}
void test(int a, int b = 1)
{
	cout << "ab" << endl;
}
int main(void)
{
	int a = 123;

	test(1);
	return 0;
}
