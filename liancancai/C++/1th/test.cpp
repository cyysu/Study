#include <iostream>

using namespace std;

// typedef unsigned int U32;

namespace myspace{
	typedef unsigned int U32;
	U32 add(U32 a, U32 b);
}

using namespace myspace;

U32 myspace::add(U32 a, U32 b)
{
	return a + b;
}
 
int main(void)
{
	cout << "add = " << add(2, 3) << endl;
	// printf("hello\n");
	return 0;
}
