#include "file.h"

Student::Student(const char *name, int age, char sex, double result)
{
	memcpy(this->name, name, strlen(name) + 1);
	this->age = age;
	this->sex = sex;
	this->result = result;
}

void Student::show(void) const
{
	cout << "name = " << name
	     << " age = " << age
     	 << " sex = " << sex
     	 << " result = " << result << endl;
}

int Student::set_student(const  char *name, int age, char sex, double result)
{
	memcpy(this->name, name, strlen(name) + 1);
	this->age = age;
	this->sex = sex;
	this->result = result;

	return 1;
}

void Student::write_student(ostream & fout)
{
	fout << this->name;
	fout << this->age;
	fout << this->sex;
	fout << this->result;
	fout << endl;
}
