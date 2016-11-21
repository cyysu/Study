#include "stack.h"

int main(void)
{
	Stack<int> stack1;
	int i;
	int num;
	for (i = 0; i < 10; i++)
	{
		stack1.push(i);
	}
	stack1.show();

	for (i = 0; i < 10; i ++)
	{
		stack1.pop(num);
		cout <<  num << endl;
	}
	stack1.pop(num);
	stack1.show();

	return 0;
}
