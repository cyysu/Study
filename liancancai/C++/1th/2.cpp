#include <iostream>

using namespace std;

namespace test{
	typedef unsigned int U32;
	U32 add(U32 num1, U32 num2);
}

using namespace test;

U32 test::add(U32 num1, U32 num2)
{
	return num1 + num2;
}

int main(void)
{
	int num1 = 10;
	int num2 = 20;	 

	cout << "add = " << add(num1, num2) << endl;
	return 0;
}