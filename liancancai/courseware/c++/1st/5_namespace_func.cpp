#include <iostream>

using namespace std;

void hello(void)
{
	cout << "hello!" << endl;
}

namespace myspace{
	int num;
	void hello(void)
	{
		cout << "space hello!" <<endl;
	}
	void love(void);
};

void myspace::love(void)
{
	cout << "love you!" << endl;
}
void love(void)
{
	cout << "extern love!" << endl;
}
int main(void)
{
	myspace::hello();
	myspace::love();
	love();
	hello();

	return 0;
}

