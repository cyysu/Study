#include <iostream>

//系统命名空间
using namespace std;

//int num = 2233;

//定义自己命名空间
namespace myspace{
	int num = 1122;
	namespace myspace1{
		int num = 3344;
		}
}; 

//表示告诉编译器去解析
using namespace myspace;
int main(void)
{

	//int num = 1234;

	//cout << "num = " << ::num << endl;//表示访问全局num
	cout << "num = " << num << endl;
	cout << "num = " << myspace::myspace1::num << endl;
	//cout << "num = " << myspace::num << endl;	
	return 0;
}
