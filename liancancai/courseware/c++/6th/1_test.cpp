#include <iostream>

using namespace std;

class A{
	public:
		void strlen();
		void test(void){cout << "test" << endl;};
		virtual void show(void) = 0;
};

class B:public A{

	public:
		virtual void show(void) = 0;
		
};

class C:public B{

	public:
		void show(void){;};
};
int main(void)
{
	//A a;
	//B b;
	//C c;
	//b.show();
	//b.test();

	c.test();

	return 0;
}

void B::show(void)
{
	cout << "BBBBB" << endl;
}
