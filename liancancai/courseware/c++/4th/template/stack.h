#ifndef __STACK_H__
#define __STACK_H__

#include <cstring>
#include <iostream>

using namespace std;

//声明一个模板
template <class Type>

class Stack{
	private:
		enum {MAX = 10};//表示栈大小
		Type stack[MAX];//表示栈
		int top;//表示栈顶元素
	public:
		Stack(void);
		bool is_full(void) const;//判断是否是满栈
		bool is_empty(void) const;//判断是否是空栈
		bool push(Type &);//压栈
		bool pop(Type &);//弹栈
		void show(void) const;
		~Stack(void);

};


template <class Type>
Stack<Type>::Stack(void)
{
	top = 0;
}

template <class Type>
Stack<Type>::~Stack(void)
{
	cout << "destructor" << endl;	
}

template <class Type>
bool Stack<Type>::is_full(void) const
{
	if (top == MAX)
		return true;
	return false;
}
template <class Type>
bool Stack<Type>::is_empty(void) const
{
	if (top == 0)
		return true;
	return false;
}
template <class Type>
bool Stack<Type>::push(Type & _data)
{
	if (is_full())
		return false;

	stack[top] = _data;
	top++;

	return true;
}

template <class Type>
bool Stack<Type>::pop(Type & _data)
{
	if (is_empty())
		return false;
	top--;
	_data = stack[top];

	return true;
}

template <class Type>
void Stack<Type>::show(void) const
{
	int i;

	for (i = 0; i < top; i++)
	{
		cout << stack[i] << " ";
	}
	cout << endl;
}

#endif /*STACK _H*/
