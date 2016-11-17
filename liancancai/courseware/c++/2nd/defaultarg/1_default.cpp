#include <iostream>

using namespace std;
//声明
void hello(void);
//实现
void hello(void)
{
	cout << "func : hello" << endl;
}

void pri(int a, double d = 0.0, char *s = "hello", char ch = 'A', string str = "hello")
{
	cout << "a = " << a << endl;
	cout << "d = " << d << endl;
	cout << "s = " << s << endl;
	cout << "ch = " << ch << endl;
	cout << "str = " << str << endl;
	cout << "this is a c++ program!" << endl;
}
void pri(char ch)
{
	cout << "option one" << endl;
}
int main(void)
{
	
	printf("============\n");
	pri(1, 1, "a");
	cout << "hello" << endl;
	hello();//调用
	pri(123, 88.88, "hello", 'A', "world");
	printf("============\n");
	pri('A');

    /*
	 *pri(1, 1, "a", 'A');
	 *printf("============\n");
	 *pri(1, 1, "a");
	 *printf("============\n");
	 *pri();
     */

	return 0;
}
