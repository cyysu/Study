
#include <iostream>

using namespace std;

//声明一个类
class C;

class A{
	private:
		int a;
	protected:
		int b;
	public:
		A(int _a = -1, int _b = -1)
		{
			a = _a;
			b = _b;
		}
		friend class C;
		void show(void){cout << "AAAA" << endl;};
		void test(void)
		{
			//C c;
			//cout << "age = " << c.age << endl;
			cout << "A-> a = " << a << endl;
		}
};

class B{

	public :
		void show(void){cout << "BBBB" << endl;};
};

class C {
	private:
		int age;
	public:
		//friend class A;
		//C(int _age){age = _age;};
		void show(void)
		{
			cout << "CCCC" << endl;
		}

		void test(void)
		{
			//定义友元类的对象
			A a(123, 456);

			cout << "test C : ";
			cout << a.a << endl;
			cout << "   " << a.b << endl;
			a.test();
		}
};

int main(void)
{
	A a;
	C c;

	a.test();
	c.test();	
	return 0;
}
