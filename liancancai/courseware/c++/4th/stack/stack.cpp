#include "stack.h"

Stack::Stack(void)
{
	memset(stack, 0, sizeof(stack));
	top = 0;
}

Stack::~Stack(void)
{
	cout << "destructor" << endl;	
}

bool Stack::is_full(void) const
{
	if (top == MAX)
		return true;
	return false;
}
bool Stack::is_empty(void) const
{
	if (top == 0)
		return true;
	return false;
}
bool Stack::push(type & _data)
{
	if (is_full())
		return false;

	stack[top] = _data;
	top++;

	return true;
}

bool Stack::pop(type & _data)
{
	if (is_empty())
		return false;
	top--;
	_data = stack[top];

	return true;
}

void Stack::show(void) const
{
	int i;

	for (i = 0; i < top; i++)
	{
		cout << stack[i] << " ";
	}
	cout << endl;
}
