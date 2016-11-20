#include <iostream>
#include <string.h>
using namespace std;

class stu{
private:
	char name[128];
	int age;
	char sex;
	double grade;
public:
	void init(const char *_name, int _age, char _sex, double _grade);
	void show(void);
	void set_name(const char *_name);
	void set_age(int _age);
	void set_sex(char _sex);
	void set_grade(double _grade);
};

void my_strcpy(char *dest, const char *src, int n)
{
	int i;

	// cout << "n = " << n << endl;
	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';
}

int my_strlen(const char *s)
{
	int i = 0;

	while(s[i] != '\0')
	{
		i++;
	}

	return i;
}

void stu::init(const char *_name, int _age, char _sex, double _grade)
{
	my_strcpy(name, _name, my_strlen(_name));
	age = _age;
	sex = _sex;
	grade = _grade;
}

void stu::show(void)
{
	cout << "name:" << name <<endl;
	cout << "age:" << age << endl;
	cout << "sex:" << sex << endl;
	cout << "grade:" << grade << endl;
}

void stu::set_name(const char *_name)
{
	my_strcpy(name, _name, my_strlen(_name));
}

void stu::set_age(int _age)
{
	age = _age;
}

void stu::set_sex(char _sex)
{
	sex = _sex;
}

void stu::set_grade(double _grade)
{
	grade = _grade;
}

int main(void)
{
	stu stu1;

	stu1.init("wag xiao ming", 21, 'M', 85.5);
	stu1.show();

	stu1.set_name("zhang san");
	stu1.set_age(99);
	stu1.set_sex('F');
	stu1.set_grade(99.9);
	stu1.show();

	return 0;
}
