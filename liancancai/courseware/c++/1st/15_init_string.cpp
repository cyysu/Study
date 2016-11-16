#include <iostream>

using namespace std;

int main(void)
{
	string one;

	cout << "one : " << one << endl;
	cout << "one.size : " << one.size() << endl;
	one = "hello";//赋值

	string two(one);//初始化 会调用构造函数
	cout << "two : " << two << endl;

	string three("hello");
	//three(one);//说明构造函数不可以脱离开定义单独调用
	cout << "three : " << three << endl;

	string four(20, '#');
	cout << "four : " << four << endl;

	three += " world";
	cout << "three : " << three << endl;
	string five(three, 3);
	cout << "five : " << five << endl;

	string six(&three[3], &three[8]);
	//string six(three + 3, three + 8);
	cout << "six : " << six << endl;

	char s[] = "this is a c++ prigram!";

	//string seven(s + 3, s + 10);
	string seven(&s[3], &s[10]);
	cout << "seven : " << seven << endl;


	return 0;
}
