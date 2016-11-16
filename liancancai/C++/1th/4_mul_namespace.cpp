#include <iostream>

using namespace std;

namespace myspace1
{
	int num = 111;
	namespace myspace2
	{
		int num = 222;
		namespace myspace3
		{
			int num = 333;
		};
	};
};

namespace myspace4
{
	void hello(void);
}

void myspace4::hello(void)
{
	cout << "myspace4 hello " << endl;
}

using namespace myspace1;
using namespace myspace2;

void hello(void)
{
	cout << "nomaly hello " << endl;
}

int main(void)
{

	cout << "myspace1 = " << myspace1::num << endl;
	cout << "myspace2 = " << myspace2::num << endl;
	cout << "myspace3 = " << myspace3::num << endl;	 

	hello();
	myspace4::hello();

	return 0;
}