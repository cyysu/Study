#ifndef __STACK_H__
#define __STACK_H__

#include <cstring>
#include <iostream>

typedef int type;
using namespace std;

class Stack{
	private:
		enum {MAX = 10};//表示栈大小
		type stack[MAX];//表示栈
		int top;//表示栈顶元素
	public:
		Stack(void);
		bool is_full(void) const;//判断是否是满栈
		bool is_empty(void) const;//判断是否是空栈
		bool push(type &);//压栈
		bool pop(type &);//弹栈
		void show(void) const;
		~Stack(void);

};

#endif /*STACK _H*/
