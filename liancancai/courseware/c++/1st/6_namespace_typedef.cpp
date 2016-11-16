#include <iostream>

using namespace std;

namespace myspace{
	typedef unsigned int U32;
	U32 num = 1234;
	U32 add(U32 a, U32 b);
};

//using namespace myspace;

//myspace::U32 myspace::add(myspace::U32 a, myspace::U32 b)
myspace::U32 myspace::add(U32 a, U32 b)
{
	return a + b;
}
int main(void)
{
	cout << "add = " << myspace::add(2, 3) << endl;
	return 0;
}
