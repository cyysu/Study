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
		A(void);//构造函数
		A(string _name, char _sex, int age);
		void set_name(string _name);
		void set_age(int _age);
		void show(void) const;
		void test(void){cout << "test" << endl;};
		~A(void);//析构函数
};

//派生类
class B : public A{
	private:
		int id;
		int num;
	protected:
	public:
		B(void){cout << "default B constructor" << endl;};
		B(int _id){id = _id;};
		B(string _name, char _sex, int _age, int _id, int _num): A(_name, _sex, _age), id(_id), num(_num){;};
		void set_id(int _id){id = _id;};
		void set_name(string _name);
		void show(void)const;
		~B(void){cout << "B => destructor" << endl;};

};

int main(void)
{
	//A a("tom", 'M', 20);
	//B b1(10001);

	B b2("mary", 'F', 18, 10002, 123);

	b2.show();

	b2.A::show();


	return 0;
}

A::A(void)
{
	cout << "default A constructor" << endl;
}
A::A(string _name, char _sex, int _age)
{
	cout << "ttttttttt" << endl;
	this->name = _name;
	this->sex = _sex;
	this->age = _age;
}

//保护
void A::set_age(int _age)
{
	this->age = _age;
}
//私有
void A::set_name(string _name)
{
	this->name = _name;
}
A::~A(void)
{
	cout << "A => destructor" << endl;
}

void A::show(void) const
{
	cout << "name : " << this->name 
		<< " sex : " << this->sex
		<< " age : " << this->age << endl;
}

void B::show(void) const
{
	cout << "id : " << id
		<< "num : " << num
		<< endl;
}

void B::set_name(string _name)
{
	A::set_name(_name);
}

