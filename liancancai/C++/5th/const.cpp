/**
 * @Author:      lcc
 * @DateTime:    2016-11-22 14:48:59
 * @Description: 测试const函数与非const函数的区别 
 */
 //编译不通过

#include <iostream>

using namespace std;

void show(void) const
{
	cout << "show const" << endl;
}

void show(void)
{
	cout << "show " << endl;
}

int main(void)
{

	return 0;
}
