#include <stdio.h>//c 
#include <iostream>//c++ 标准输入输出头文件

using namespace std;

void test(void)
{
	cout << "test!" << endl;
}
int main(void)
{

	test();
	//printf("this is a c++ program!\n");
	//::表示域名空间解析运算符
	cout << "hello" << endl;

	std::cout << "this is a c++ program!" << std::endl;
	return 0;
}
