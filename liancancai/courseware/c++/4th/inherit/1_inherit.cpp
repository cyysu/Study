#include <iostream>

using namespace std;

class A{
	private:
		string name;
	protected:
		int age;
	public:
		char sex;
		double result;
};

class B : public A{
	private:
		int id;
	public:
		double result;
};

int main(void)
{
	A a;
	B b;

	b.result = 1122;
	a.sex = 'F';
	

	//b.sex = 'M';
	//b.age = 20;

	cout << "b.result : " << b.result << endl;
	cout << "a.result : " << a.result << endl;
	cout << "a.sex : " << a.sex << endl;
	cout << "b.sex : " << b.sex << endl;
	return 0;
}
