#include <iostream>

using namespace std;

template <typename T>
void show(T a)
{
	cout << a <<endl;
}

int main(void)
{
	int a = 1;
	float f = 2.22;
	double d = 3.333;
	char c = 'A';
	string str = "hello";	

	show(a);
	show(f);
	show(d);
	show(c);
	show(str);

	return 0;
}

//template <typename T>
//void show(T a)
//{
//	cout << a <<endl;
//}
