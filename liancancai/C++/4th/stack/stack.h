#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
using namespace std;

#define STACK_NUM 20

template <class Type>

class Stack{
private:
	Type stack[STACK_NUM];
	int top;
public:
	int push(Type & type);
	int pop(Type & type);
	void show(void) const;
	int is_full(void) const;
	int is_empty(void) const;
	Stack(void);
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
	top = 0;
}

template <class Type>
int Stack<Type>::is_full(void) const
{
	if(top >= STACK_NUM)
	{
		return 1;
	}
	else
	{
		return 0; 
	}
}

template <class Type>
int Stack<Type>::is_empty(void) const
{
	if (top <= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
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

template <class Type>
int Stack<Type>::push(Type & type)
{
	if(is_full())
	{
		cout << "the stack is full" << endl;
		return 0;
	}
	else
	{
		stack[top] = type;
		top++;
		return 1;
	}
}

template <class Type>
int Stack<Type>::pop(Type & type)
{
	if(is_empty())
	{
		cout << "the stack is empty" << endl;
		return 0;
	}
	else
	{
		top --;
		type = stack[top];
		return 1;
	}
}

#endif