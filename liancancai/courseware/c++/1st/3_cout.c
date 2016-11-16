#include <iostream>
#include <stdio.h>

using namespace std;

//定义自己命名空间
namespace myspace{
	int num = 1122;
}

int main(void)
{
	int a = 1, b = 2;
	float f = 2.33;
	bool c = true;
	c = false;
	//cout << "num = " <<	num << endl;
	printf("a = %d b = %d\n", a, b);
	cout << "a = " << a << " b = " << b << endl;//输出语句
	cout << "f = " << f << endl;
	cout << "c = " << c << endl;
	return 0;
}
