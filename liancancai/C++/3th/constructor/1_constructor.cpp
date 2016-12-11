#include <iostream>
#include <string.h>

using namespace std;

class student{
private:
	char name[128];
	int age;
	char sex;
protected:
public:
	student(const char *_name = "no name", int _age = -1, char _sex = 'N');
	void show(void);
	void set_all(const char *_name, int _age, char _sex);
};

student::student(const char *_name, int _age, char _sex)
{	
	strncpy(name, _name, strlen(_name) + 1);
	age = _age;
	sex = _sex;
}

void student::show(void)
{
	cout << "name = " << name << endl;
	cout << "age = " << age << endl;
	cout << "sex = " << sex << endl;
}

void student::set_all(const char *_name, int _age, char _sex)
{
	strncpy(name, _name, strlen(_name) + 1);
	age = _age;
	sex = _sex;
}

int main(void)
{
	student stu1;
	stu1.show();

	stu1.set_all("zhang san", 22, 'F');
	stu1.show();
	return 0;
}
