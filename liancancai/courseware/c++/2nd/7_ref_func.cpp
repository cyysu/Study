#include <iostream>

using namespace std;

//传变量值
void swap1(int a, int b)
{
	int tmp;

	tmp = a;
	a = b;
	b = tmp;
}
//传变量地址
void swap2(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	
}
//传引用
void swap3(int & a, int & b)
{
	int tmp;

	tmp = a;
	a = b;
	b = tmp;

}
int main(void)
{
	int a = 1, b = 2;

	cout << "a = " << a << " b = " << b << endl;
	//swap1(a, b);
	//swap2(&a, &b);
	swap3(a, b);
	cout << "a = " << a << " b = " << b << endl;
	return 0;
}
