#include <iostream>

using namespace std;

int main(void)
{
	//枚举常量
	enum {a, b = 10, c, d, e, f};

	//b = (enum) (20);
	cout << "a = " << a <<  endl;
	cout << "b = " << b <<  endl;
	cout << "c = " << c <<  endl;
	cout << "d = " << d <<  endl;
	cout << "e = " << e <<  endl;
	return 0;
}
