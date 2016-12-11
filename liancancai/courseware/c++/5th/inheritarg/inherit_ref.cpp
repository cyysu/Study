
#include <iostream>

using namespace std;

//基类
class A{
	private:
		string name;
		char sex;
	protected:
		int age;
	public:
		A(string _name = "noname", char _sex = 'N', int age = -1);
		//virtual void show(void) const{cout << "AAAAA" << endl;};
		virtual void show(void) = 0;//纯虚函数
		~A(void){;};//析构函数
};

//派生类
class B : public A{
	private:
		int id;
	protected:
	public:
		B(int _id = -1){id = _id;};
		//void show(void)const{cout << "BBBBB" << endl;};
		void show(void){cout << "BBBBB" << endl;};
		~B(void){;};

};

class C: public A{
	public:
		//void show(void) const {cout << "CCCCC" << endl;};
		void show(void) {cout << "CCCCC" << endl;};
};

/*
 *void pri_class(A & a)
 *{
 *    a.show();
 *}
 */
int main(void)
{
	//A a;
	B b;
	C c;

    /*
	 *A & val1 = a;
	 *A & val2 = b;
     */

    /*
	 *val1.show();// A::show
	 *val2.show();// B::show()
     */
    /*
	 *pri_class(a);
	 *pri_class(b);
	 *pri_class(c);
     */

	return 0;
}

A::A(string _name, char _sex, int _age)
{
	this->name = _name;
	this->sex = _sex;
	this->age = _age;
}

