#include <iostream>
#include <string.h>

using namespace std;

//定义类
class student{
	private:
		char name[128];
		int age;
		char sex;
	protected:
	public:
		//函数声明
		student(void);//构造函数
		student(char * _name, int _age);
		student(char * _name, int _age = 20, char _sex = 'N');
		void init(void);
		void init(char * _name, int _age, char _sex);
		void show(void);

};
int main(void)
{
	student cls;	
	student stu("tom");

	//stu.show();
	//stu.student();

	//student cls[5];
/*
 *    student *p;
 *
 *    p = new student;
 */
	//cls_t cls = {"jim", 20, 'F'};

    /*
	 *cls.init();
	 *cls.init("tom", 18, 'M');
     */
	return 0;
}

student::student(void)
{
	//cout << "welcome student!\n";
	cout << "default constructor" << endl;
	memset(name, 0, sizeof(name));
	age = 0;
	sex = ' ';
}
student::student(char * _name, int _age)
{
	cout << "two constaructor" << endl;
}

student::student(char * _name, int _age, char _sex)
{
	cout << "constructor" << endl;
    /*
	 *strcpy(name, _name);
	 *age = _age;
	 *sex = _sex;
     */

}
void student::init(void)
{
	memset(name, 0, sizeof(name));
	age = 0;
	sex = ' ';
}
void student::init(char * _name, int _age, char _sex)
{
	strcpy(name, _name);
	age = _age;
	sex = _sex;
}

void student::show(void)
{
	cout << "name : " << name << " age : " << age
		<< "  sex : " << sex << endl;
}


