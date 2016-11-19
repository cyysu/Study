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
		~student(void);//析构函数
};

//定义一个全局对象
//student e;

void test(void)
{
	cout << "test stat!" << endl;
	student temp;//局部变量
	cout << "test end!\n";
}
int main(void)
{
	cout << "main stat!" << endl;
	//student cls;	
	student *p = NULL;

	p = new student;
	if (p == NULL)
	{
		printf("new failed!\n");
		return -1;
	}
	delete p;

	test();
	//student stu("tom");

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
	 cout << "main end!" << endl;
	return 0;
}

student::~student(void)
{
	cout << "destructor" << endl;
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


