#include <iostream>

using namespace std;

class A{
	public:
		void show(void){cout << "AAAA" << endl;};
};
class B{

	public :
		void show(void){cout << "BBBB" << endl;};
};

class C : public A, private B{
	public:
		void show(void)
		{
			cout << "CCCC" << endl;
			this->B::show();
		}
};

int main(void)
{
	A a;
	B b;
	C c;

	c.A::show();
	//c.B::show();
	cout << "==========" << endl;
	a.show();
	b.show();
	c.show();
	return 0;
}
