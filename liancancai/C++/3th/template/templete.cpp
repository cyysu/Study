#include <iostream>

using namespace std;

#define con 1 


//引用

void Swap(int  & a, int & b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;

	cout << "normal:Swap" << endl;
}


//模板
template<typename T>
void Swap(T & a, T & b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;

	cout << "template:Swap" << endl;
}

//显示具体化
template <> void Swap(int & a, int & b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;

	cout << "embodimen:Swap" << endl;
}

template<typename T>
void show(T & a, T & b)
{	
	cout << a << endl;
	cout << b << endl;
}

//普通函数>实现具体化>模板
int main(void)
{
	int a = 1, b = 2;

	cout << "before" << endl;
	show(a, b);

	Swap(a, b);
	cout << "after" << endl;
	show(a, b);

	return 0;
}
