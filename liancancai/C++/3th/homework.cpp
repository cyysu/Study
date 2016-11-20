#include <iostream>
#include <string.h>

using namespace std;

class my_stack{
private:
	int *n;
	static int num;
public:
	my_stack(void);
	void show(void);
	void push(int _n);
	int pop(void);
	~my_stack(void);
	int size(void) const; //返回num的数值
};

int my_stack::num = 0;

int main(void)
{
	my_stack stk;
	int i;

	cout << "测试圧栈===================" << endl;
	for (i = 2; i < 10; i ++) //测试圧栈
	{
		stk.push(i);
	}
	stk.show();
	cout << "size = " << stk.size() << endl;

	cout << "测试出栈===================" << endl;
	for (i = 2; i < 10; i ++)//测试出栈
	{
		cout << "pop = " << stk.pop() << endl;
	}
	cout << "size = " << stk.size() << endl;

	cout << "测试当栈空时继续出栈=========" << endl;
	stk.pop();

	cout << "测试重新圧栈================" << endl;
	stk.push(11);
	stk.show();
	cout << "size = " << stk.size() << endl;

	return 0;
}

my_stack::my_stack(void)
{
	n = NULL;
}

my_stack::~my_stack(void)
{
	delete n;
	num = 0;
}

void my_stack::show(void)
{
	int i;

	for (i = 0; i < num; i++)
	{
		cout << n[i];
		cout << " ";
	}
	cout << endl;
}

void my_stack::push(int _n)
{
	int *p = NULL;

	//动态申请栈的大小
	p = n;
	n = new int [num + 1];
	memcpy(n, p, sizeof(int) * num);
	memcpy(n + num, &_n, sizeof(int));
	delete p;

	num ++;
}

int my_stack::pop(void)
{
	int *p = NULL;
	int temp;

	num --;
	temp = n[num];
	if (num < 0)//判断是否为空栈
	{
		cout << "the stack is empty" << endl;
		num = 0;
		return -1;
	}

	//动态申请栈的大小
	p = n;
	n = new int [num];
	memcpy(n, p, sizeof(int) * num);
	delete p;
	
	return (temp);
}

int my_stack::size(void) const
{
	return num;
}